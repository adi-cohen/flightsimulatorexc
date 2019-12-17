//
// Created by adi on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_CONNECTCLIENTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCLIENTCOMMAND_H


#include <vector>
#include <string>
#include "Command.h"

using namespace std;
class ConnectClientCommand: public Command {
public:
    int execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope);
};

#endif //FLIGHTSIMULATOR_CONNECTCLIENTCOMMNAD_H

