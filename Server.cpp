//
// Created by yaron on 19/12/2019.
//

#include <netinet/in.h>
#include "Server.h"
#include "MutexClass.h"

void* Server::runServer(void *arg) {
    ArgumentForServerRunning* arguments = (ArgumentForServerRunning*) arg;
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n, temp;
    Parser* parser = arguments->parser;
    ArgumentForVarUpdating* forVarUpdating = new ArgumentForVarUpdating();
    forVarUpdating->parser = parser;


    /* First call to socket() function */
    do{
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
    } while(n < 0);


    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = arguments->portNum;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    do {
        temp = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    } while(temp < 0);

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // create instance of mutex class
    pthread_mutex_t* mutex = MutexClass::getInstance()->getMutex();
    // lock the thread
    pthread_mutex_lock(mutex);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    // if the client accepted the connection - unlock the thread
    pthread_mutex_unlock(mutex);

    // call a method in the parser
    parser->signalFlightGearRunning(true);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while(true) {
        /* If connection is established then start communicating */
        bzero(buffer,256);
        do {
            n = read( newsockfd,buffer,255 );
        } while(n < 0);

        /* Write a response to the client */
        do {
            n = write(newsockfd,"I got your message",18);
        } while(n < 0);

        string str = buffer;
        forVarUpdating->buffer = str;
        // TODO update somehow the varoables in our server
        //Server::updateVariables(forVarUpdating);

        // call a method in the parser
        if(parser->checkServerClose()) {
            close(sockfd);
            break;
        }
        usleep(1 / arguments->frequency * 1000);
    }
}


