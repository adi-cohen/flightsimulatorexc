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

#define PORT 5400
// open a data server and then call a thread to run it.
int OpenDataServer :: execute(vector<string> strings,map<string, Var*> varMap, map<string, Var*> simMap, int index) {
    return index +3;
    //todo only when it works!
    // make sure we have 2 arguments only
    if(strings.size() != 2) {
        // no good arguments error
        return -1;
    }

    // the generic code to open a sever.
    int newsockfd, portno, clilen;
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
    portno = stoi(strings[0]); // the first parameter is the port num

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(PORT);
    //we need to convert our number
    // to a number that the network understands.*/

    /* Now bind the host address using bind() call.*/
    if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return -3;
    }

    /* Now start listening for the clients, here process will
    * go in sleep mode and will wait for the incoming connection
    */
    int wait = stoi(strings[1]);
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        return -4;
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    clilen = sizeof(cli_addr);

    // accepting a client
    newsockfd = accept(socketfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    //printf("connection made");
    if (newsockfd < 0) {
        perror("Error accepting client");
        return -5;
    }

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
    //thread t1(newsockfd, wait);
    // let it run seperatly from the main code.
    //t1.detach();
    return 2;

    //close(socketfd); //closing the listening socket

}
