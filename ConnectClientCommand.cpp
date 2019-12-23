//
// Created by yaron on 13/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "CreateVarCommand.h"
#include "ConnectClientCommand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <mutex>

#define PORT 5402
using namespace std;

int ConnectClientCommand::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {

    // should work
    string portAndIp = stringVector.at(index + 1);
    vector<string> param = split(portAndIp, ',');
    string portNum = param.at(1);
    string ipFirst = param.at(0);
    string ip = "";
    for (auto c:ipFirst) {
        if (c != '"') {
            ip = ip + c;
        }
    }

    //create socket
    //string portNum = "5402";
    //string ip = "127.0.0.1";
    //create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        throw "Could not create a socket" ;
    }
    //We need to create a sockaddr obj to hold address of server
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(ip.c_str());  //the localhost address
    address.sin_port = htons(stoi(portNum));
    //we need to convert our number (both port & localhost)
    // to a number that the network understands


    // Requesting a connection with the server on local host with port
    std::cout << "try to connect to simulator" << std::endl;
    //we need todo it with loop?? until connecting
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        throw "connected failed" ;
    }
    std::cout << "connected succeeded" << std::endl;

    //writing back to client
    std::thread clientThread(writeToSimulator, symTable, client_socket); //
    std::this_thread::sleep_for(std::chrono::seconds(1));
    clientThread.detach();
    return index + 3;
}

vector<std::string> ConnectClientCommand::split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

void writeToSimulator(SymbolTable *symTable, int client_socket) {
    while (true) {
        if (!symTable->QueueSetValToSim.empty()) {
            const char *val = symTable->QueueSetValToSim.front();
            send(client_socket, val, strlen(val), 0);
            //std::cout << "new val sent to sim" << std::endl;
            symTable->QueueSetValToSim.pop();
        }
    }
}
