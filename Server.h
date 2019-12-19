//
// Created by yaron on 19/12/2019.
//

#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H
#include "Parser.h"

struct ArgumentForServerRunning {
    double portNum;
    double frequency;
    Parser* parser;
};

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
