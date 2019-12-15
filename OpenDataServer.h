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
    int execute(vector<string> strings,map<string, Var*> varMap, map<string, Var*> simMap, int index);
};

#endif //FLIGHTSIMULATOR_OPENDATASERVER_H
