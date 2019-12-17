//
// Created by adi on 16/12/2019.
//

#ifndef FLIGHTSIMULATOR_SYMBOLTABLE_H
#define FLIGHTSIMULATOR_SYMBOLTABLE_H

#include "map"
#include "string"
#include "Var.h"
using namespace std;

class SymbolTable {
public:
    map<string, Var *>* ptrVarMap;
    map<string, Var *>* ptrSimMap;
    int scope;
    int index;
    SymbolTable(map<string, Var *>* ptrVarMap,map<string, Var *>* ptrSimMap,int scope,int index);
public:
    void addVariable(Var v);
    Var* getVariable(string s);
    bool isVariable(string s);
    void updateVariable(string s, double);
};


#endif //FLIGHTSIMULATOR_SYMBOLTABLE_H
