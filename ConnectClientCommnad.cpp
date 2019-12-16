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


int ConnectClientCommand :: execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index) {

    // should work
    string ip = strings.at(index+1);
    string port = strings.at(index+2);
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
    address.sin_port = htons(stoi(port));
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
        exit(2);
    } else {
        std::cout << "Client is now connected to server" << std::endl;
    }

    return index + 3;
    //todo only when it works!

    // the general client code
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[] = "i am the king";
    // we should recieve IP and Port as as strings
    if (strings.size() != 2) {
        // bad arguments error
        return -1;
    }
    // convert a string to integer - the port number
    portno = stoi(strings[1]);

    // Create a socket point
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -2;
    }

    // get the host
    server = gethostbyname(strings[0].c_str());
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -3;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    // Now connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) {
        perror("ERROR connecting");
        return -4;
    }
    // set the socket to be the correct socket number*/

}
