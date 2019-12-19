//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <utility>
#include <vector>
#include <string>
#include <map>
#include "SymbolTable.h"
class SymbolTable;
using namespace std;
class Var {
    string varName;
    bool varUpdateSim;
    string sim;
    int scope;
public:
    double value;
    //todo not sure we need the constructor because of the update function
    Var(string name, double val, bool update, string sim1, int scope) ;
    void updateVal(string newVal, SymbolTable* symTable);
    string getName();
};

class SymbolTable {
public:

    map<string, Var*> varMap;
    map<string, Var*> simMap;
    SymbolTable(map<string, Var*> ptrVarMap, map<string, Var*> ptrSimMap);
};

#endif //FLIGHTSIMULATOR_VAR_H
