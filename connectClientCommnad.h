//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_CONNECTCLIENTCOMMNAD_H
#define FLIGHTSIMULATOR_CONNECTCLIENTCOMMNAD_H

#include <vector>
#include <string>
#include "Command.h"

using namespace std;
class connectClientCommand: public Command {
 public:
    int execute(vector<string> strings);
};

#endif //FLIGHTSIMULATOR_CONNECTCLIENTCOMMNAD_H
