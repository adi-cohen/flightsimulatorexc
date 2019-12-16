//
// Created by adi on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_CONNECTCLIENTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCLIENTCOMMAND_H


#include <vector>
#include <string>
#include <netinet/in.h>
#include "Command.h"

using namespace std;
class ConnectClientCommand: public Command {
public:
    int execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index);
    sockaddr_in address;
    int client_socket;
};

#endif //FLIGHTSIMULATOR_CONNECTCLIENTCOMMNAD_H

