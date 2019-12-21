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
#include <thread>

#define PORT 5402
int ConnectClientCommand :: execute(vector<string> stringVector,DataReaderServer *server, SymbolTable *symTable, int index, int scope) {
    //return index + 3;
    string portno = "5402";
    string ip = "127.0.0.1";
    //create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        exit(1);
    }
    //We need to create a sockaddr obj to hold address of server
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(ip.c_str());  //the localhost address
    address.sin_port = htons(stoi(portno));
    //we need to convert our number (both port & localhost)
    // to a number that the network understands


    // Requesting a connection with the server on local host with port
    std::cout << "try to connect to simulator" << std::endl;
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "connected failed" << std::endl;
        exit(2);
    } else {
        std::cout << "connected succeeded" << std::endl;
    }

    //thread t2();
    return index + 3;
}
