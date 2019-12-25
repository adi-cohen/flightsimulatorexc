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
#include <thread>
#include <mutex>
#include "OpenDataServer.h"
#include "DataReaderServer.h"

#define PORT 5401
//std::mutex mutex_lock;

// open a data server and then call a thread to run it.
int OpenDataServer::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {

    //int simulatorClient, portnum;
    //struct sockaddr_in serv_addr, cli_addr;

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket";
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(PORT);
    //we need to convert our number
    // to a number that the network understands.


    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }

//making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (client_socket == -1) {
        throw "Error accepting client";
    }

    close(socketfd); //closing the listening socket

    thread serverThread(readFromSimulator, symTable, client_socket);
    serverThread.detach();
    //std::this_thread::sleep_for(std::chrono::seconds(20));
    //todo remove
    cout << "the programs go on open" << endl;
//    while (true){
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    }
    return index + 3;
}


void readFromSimulator(SymbolTable *symTable, int client_socket) {
    cout << "hi" << endl;
    //reading from client
    char buffer[1024] = {0};
    // keep running while we have a connection.
    // read simPathToValFromSimMap into the buffer
    while (true) {
        int valread = read(client_socket, buffer, 1024);
        if (valread == -1) {
            // error reading from socket
            throw " read zero or less from sim socket";
        }
        int n;
        double doubleVal;
        string doubleInString, pathInSim;
        istringstream bufferStream(buffer);
        while (getline(bufferStream, doubleInString)) {
            istringstream doubleInStram(doubleInString);
            int i = 1;
            while (getline(doubleInStram, doubleInString, ',')) {
                // save out a number
                doubleVal = strtod(doubleInString.c_str(), nullptr);
                // get the right strings for the positions
                pathInSim = symTable->indexFromXmlToValMap[i];
                // update the value in the dataReaderServer's map!
                symTable->mutex.lock();
                symTable->simPathToValFromSimMap[pathInSim] = doubleVal;
                symTable->mutex.unlock();
                i++;
            }
            bufferStream.clear();
        }
        symTable->printXML();
        // after we received 36 values from the simulator, we would like to update the SimMap
        for (int j = 1; j <= 36; j++) {
            // for each index we lock & unlock
            symTable->mutex.lock();
            string stringToCompare = symTable->indexFromXmlToValMap[j];
            // update the value in the simMap ACCORDING the XML data
            symTable->updateVariableInSimMap(stringToCompare,
                                             symTable->getValue(stringToCompare));
            // if the value of the current string is equal we unlock anyway
            symTable->mutex.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
}
