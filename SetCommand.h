//
// Created by adi on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_SETCOMMAND_H
#define FLIGHTSIMULATOR_SETCOMMAND_H
#include <vector>
#include <string>
#include "Command.h"
using namespace std;
class SetCommend: public Command {
public:
    int execute(vector<string> stringVector, map<string,Var*>varMap, map<string,Var*>simMap, int index);

    string doubleToString(double calc) ;
};
#endif //FLIGHTSIMULATOR_SETCOMMAND_H
