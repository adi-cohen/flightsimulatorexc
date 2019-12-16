//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H
#include <vector>
#include <string>
#include "Command.h"
using namespace std;
class SleepCommand: public Command {
public:
    int execute(vector<string> strings,map<string, Var*> varMap, map<string, Var*> simMap, int index);
};

#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
