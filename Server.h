//
// Created by yaron on 19/12/2019.
//

#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H
#include "Parser.h"

// FOR CLIENT CONNECTION
struct ArgumentForServerRunning {
    double portNum;
    double frequency;
    Parser* parser;
};

// FOR THE OPEN DATA SERVER WHEN WE READ LINES OF XML DATA FROM THE SIMULATOR
struct ArgumentForVarUpdating {
    string buffer;
    Parser* parser;
};


class Server {

public:
    /* The following method will open a server, after the accept of connection to the server
    *
     */
    static void *runServer(void *arg);
};
#endif //FLIGHTSIMULATOR_SERVER_H
