//
// Created by yaron on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_CONDITIONPARSER_H
#define FLIGHTSIMULATOR_CONDITIONPARSER_H
#include "Command.h"

class conditionParser : public Command {
public:
    vector<Command> cmd;
public:
    int execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope);
};
#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
