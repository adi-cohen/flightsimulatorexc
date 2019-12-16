//
// Created by yaron on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "Command.h"

class printCommand : public Command  {
public:
    int execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index);
};
#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
