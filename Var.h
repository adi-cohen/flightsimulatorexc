//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Var {
    string varName;
    bool varUpdateSim;
    string sim;
    string scope;
public:
    double value;
    //todo not sure we need the constructor because of the update function
    Var(string name, double val, bool update, string sim1, string scope) ;
    void updateVal(string newVal, map<string, Var*> varMap, map<string, Var*> simMap);
    string getName();
};

#endif //FLIGHTSIMULATOR_VAR_H
