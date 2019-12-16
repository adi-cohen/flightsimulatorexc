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


int ConnectClientCommand :: execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index) {
    index = index + 1;
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
    portno = stoi(strings[index]);

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
    // set the socket to be the correct socket number/
    index = index + 1;
    return index;
}
