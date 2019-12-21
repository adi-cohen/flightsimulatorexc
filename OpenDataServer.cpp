//
// Created by yaron on 13/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include "OpenDataServer.h"
#include "thread"

bool isSimulatorCommunicatedWithUs; //main

static bool isConnected = false;

void OpenDataServer::readFromSim(int port) {
    while (!isConnected) {
        //create socket
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            //error
            throw "Could not create a socket";
        }

        //bind socket to IP address
        // we first need to create the sockaddr obj.
        sockaddr_in address; //in means IP4
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
        address.sin_port = htons(port);
        //we need to convert our number
        // to a number that the network understands.

        //the actual bind command
        if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
            throw "Could not bind the socket to an IP";
        }

        //making socket listen to the port
        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            throw "Error during listening command";
        } else {
            std::cout << "Server is now listening ..." << std::endl;
            isConnected = true;
        }

        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);

        if (client_socket == -1) {
            throw "Error accepting client";
        } else {
            //let the main continue
            isSimulatorCommunicatedWithUs = true;
        }
        close(socketfd); //closing the listening socket
        //reading from client
        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);
        std::cout << buffer << std::endl;
    }
}


// open a data server and then call a thread to run it.
int OpenDataServer::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {


    int port = stoi(stringVector.at(index + 1));
    isSimulatorCommunicatedWithUs = false;
    std::thread connectToSimAndReading(readFromSim, port);
    while (isSimulatorCommunicatedWithUs == false) {
        sleep(1);
    }
    return index + 3;

}
