//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_OPENDATASERVER_H
#define FLIGHTSIMULATOR_OPENDATASERVER_H

#include <vector>
#include <string>
#include "Command.h"

using namespace std;
class OpenDataServer: public Command {
public:
    int execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope);


    static void readFromSim(int port);
};

#endif //FLIGHTSIMULATOR_OPENDATASERVER_H
