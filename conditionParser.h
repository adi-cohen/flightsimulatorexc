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
    int execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index);
};
#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
