//
// Created by adi on 12/12/2019.
//

#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include "Var.h"
using namespace std;
extern int socketfd;
/**
 * command Interface
 */
class Command {

public:
    virtual int execute(vector<string> stringVector, map<string, Var*> varMap, map<string, Var*> simMap, int index)= 0;
};


#endif //FLIGHTSIMULATOR_COMMAND_H
