//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <utility>
#include <vector>
#include <string>
#include <map>
#include "Command.h"

using namespace std;
class Var {



    string varName;
    double value;
    bool updateSimulator;
    string sim;
    string scope;
public:
    //todo not sure we need the constructor because of the update function
    Var(string name, double val, bool update, string sim1, string scope) ;


    void updateVal(double newVal, map<string, Var*> varMap, map<string, Var*> simMap);

};

#endif //FLIGHTSIMULATOR_VAR_H
