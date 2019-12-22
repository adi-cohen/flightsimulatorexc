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
int OpenDataServer::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {

   // serverThread = thread(runServer,symTable);
    std::thread serverThread(runServer,symTable); //
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while (!symTable->isConnected){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    serverThread.detach();
    //todo remove
    cout << "the programs go on"<<endl;
//    while (true){
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    }
}

void runServer(SymbolTable *symTable) {

    DataReaderServer *server = new DataReaderServer();

    int simulatorClient, portnum;
    struct sockaddr_in serv_addr, cli_addr;

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket" ;

    }

    /* Initialize socket structure */
    // set all the socket structures with null values by using bzero function
    bzero((char *) &serv_addr, sizeof(serv_addr));
    // by using stoi we convert a string to integer type
    //portnum = stoi(stringVector[0]); // the first parameter is the port num
    portnum = 5401; // for debug

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portnum);


    /* Now bind the host address using bind() call.*/
    if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw "ERROR on binding";
    }

    /* Now start listening for the clients, here process will
    * go in sleep mode and will wait for the incoming connection
    */
    //int wait = stoi(stringVector[1]);
    string clilen = "127.0.0.1"; // for debug
    int wait = stoi(clilen);
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command" ;
    } else {
        std::cout << "Server is now listening ... Waiting for simulator to connect" << std::endl;
    }

    clilen = sizeof(cli_addr);
    // accepting a client
    simulatorClient = accept(socketfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (simulatorClient < 0) {
        cout<<"here";
        throw "Error accepting client";
    }

    cout << "Simulator is connected" << endl;


    char buffer[1024];
    bzero(buffer, 1024);
    int n;
    while(true) {
        // keep running while we have a connection.
        // read values into the buffer
        n = read(simulatorClient, buffer, 1024);
        if (n <= 0) {
            // error reading from socket
            //todo remove later
            cout << " read zero or less";
            break;
        }
        symTable->isConnected = true;
        // create a string stream from the buffer
        istringstream strm(buffer);
        double doubleValue;
        string str1;
        string path;
        int i;
        // get a line from the stream, the delimiter is ,
        while(getline(strm, str1)) {
            istringstream strm2(str1);
            i = 1;
            while (getline(strm2, str1, ',')) {
                // save out a number
                doubleValue = strtod(str1.c_str(), nullptr);
                // get the right strings for the positions
                path = server-> getPathByIndex(i);
                // update the value in the dataReaderServer's map!
                server->setValue(doubleValue, path);
                i++;
            }
            strm.clear();
        }
        // for debug
        server->printXML();
        double t = wait / 10.0;
        int wait2 = t*1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(wait2));
    }
   // close(simulatorClient);



}
