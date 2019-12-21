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
#include "OpenDataServer.h"
#include "DataReaderServer.h"

#define PORT 5400
// open a data server and then call a thread to run it.
int OpenDataServer::execute(vector<string> stringVector, DataReaderServer *server, SymbolTable *symTable, int index,
                            int scope) {
    //return index + 3;
    // the generic code to open a sever.
    int newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return -2;
    }

    /* Initialize socket structure */
    // set all the socket structures with null values by using bzero function
    bzero((char *) &serv_addr, sizeof(serv_addr));
    // by using stoi we convert a string to integer type
    //portno = stoi(stringVector[0]); // the first parameter is the port num
    portno = 5400; // for debug

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


    /* Now bind the host address using bind() call.*/
    if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return -3;
    }

    /* Now start listening for the clients, here process will
    * go in sleep mode and will wait for the incoming connection
    */
    //int wait = stoi(stringVector[1]);
    string clilen = "127.0.0.1"; // for debug
    int wait = stoi(clilen);
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        return -4;
    } else{
        std::cout<<"Server is now listening ... Waiting for simulator to connect"<<std::endl;
    }
    clilen = sizeof(cli_addr);

    // accepting a client
    newsockfd = accept(socketfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    if (newsockfd < 0) {
        perror("Error accepting client");
        return -5;
    }

    cout << "Simulator was connected" << endl;

    char buffer[400];
    bzero(buffer, 400);
    int n;
    // read
    while(true) {
        n = read(newsockfd, buffer, 400);
        if (n > 0) {
            //the connection has been made and we can continue
            break;
        }
    }

    // create a new thread that will update the values from the simulator
    //thread t1(updateVals, newsockfd, wait, server, symTable);
    updateVals(newsockfd, wait, server, reinterpret_cast<symbolTable *>(symTable));

    // let it run seperatly from the main code.
    //t1.detach();
    return index + 1;
}