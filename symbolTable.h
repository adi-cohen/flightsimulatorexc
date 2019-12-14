//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_SYMBOLTABLE_H
#define FLIGHTSIMULATOR_SYMBOLTABLE_H

//#include "variable.h"
#include <map>
class variable;
using namespace std;
class symbolTable {
private:
    map<string, variable> variables;
    map<string, variable> binded;
public:
    void addVariable(variable v);
    variable* getVariable(string s);
    bool isVariable(string s);
    void bindVariable(string name, string bindTo);
    void updateVariable(string s, double);
};

#endif //FLIGHTSIMULATOR_SYMBOLTABLE_H
