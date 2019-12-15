//
// Created by adi on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_EQUALCOMMAND_H
#define FLIGHTSIMULATOR_EQUALCOMMAND_H
#include <vector>
#include <string>
#include "Command.h"
using namespace std;
class EqualCommend: public Command {
public:
    int execute(vector<string> stringVector, map<string,Var>varMap, map<string,Var>simMap, int index);
};
#endif //FLIGHTSIMULATOR_EQUALCOMMAND_H
