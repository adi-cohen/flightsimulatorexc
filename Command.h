//
// Created by adi on 12/12/2019.
//

#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include "Var.h"
#include "SymbolTable.h"
using namespace std;
extern int socketfd;
/**
 * command Interface
 */
class Command {

public:
    virtual int execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope)= 0;
};


#endif //FLIGHTSIMULATOR_COMMAND_H
