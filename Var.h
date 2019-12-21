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
//class DataReaderServer;
using namespace std;
class Var {
    bool varUpdateSim;
    string sim;
    int scope;
    // todo - new for the threads
/*private:
    bool isServer;
    bool isVar;
    bool setBind;
    string name;
    string bindTo;
    SymbolTable* table;
    DataReaderServer* server;
    double value;
    // todo - new for the threads
/*public:
    // create a variable with no value
    Var(string name, SymbolTable* t, DataReaderServer* s) {
        this->name = name;
        this->table = t;
        this->server = s;
        value = 0;
        this->isServer = false;
        this->isVar = false;
        this->setBind = false;
    }
    // create a variable using a value
    Var(string name, SymbolTable* t, DataReaderServer* s, double d) {
        this->name = name;
        this->table = t;
        this->value = d;
        this->server = s;
        this->isServer = false;
        this->isVar = false;
        this->setBind = false;
    }
    // create a null variable that is all empty
    Var() {
        this->name = "";
        this->server = nullptr;
        this->table = nullptr;
        this->value = 0;
        this->isServer = false;
        this->isVar = false;
        this->setBind = false;
    }
    // return the name of the variable
    string myName() {
        return name;
    }
    double calculate();
    void bind(string s);
    void setOnlyBind(string s);
    // return the string we are bound to
    string boundTo() {
        return bindTo;
    }
    // check if binded to the server
    bool isBindedServer() {
        return isServer;
    }
    // check if binded to variable
    bool isBindedVar() {
        return isVar;
    }
    bool isBindedSetOnly() {
        return setBind;
    };
    void setValue(double d);*/

public:
    string varName;
    double value;
    //todo not sure we need the constructor because of the update function
    Var(string name, double val, bool update, string sim1, int scope) ;
    void updateVal(string newVal, SymbolTable* symTable);
    string getName();
    void setValue(double d);
};

class SymbolTable {
public:
    map<string, Var*> varMap;
    map<string, Var*> simMap;
    SymbolTable(map<string, Var*> ptrVarMap, map<string, Var*> ptrSimMap);
    void addVariable(Var *v);
    bool isVariable(string s);
    Var *getVariable(string s);
    void updateVariable(string s, double d);
};

#endif //FLIGHTSIMULATOR_VAR_H
