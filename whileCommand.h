//
// Created by yaron on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "Command.h"

class whileCommand : public Command {
public:
    int execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index);

};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
