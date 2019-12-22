//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H

#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "SymbolTable.h"
class SymbolTable;
//class DataReaderServer;
using namespace std;
class Var {
    bool varUpdateSim;
    string sim;
    int scope;
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
    bool isConnected = false;
    SymbolTable(map<string, Var*> ptrVarMap, map<string, Var*> ptrSimMap);
    void addVariable(Var *v);
    bool isVariable(string s);
    Var *getVariable(string s);
    void updateVariable(string s, double d);
    queue<const char *> QueueSetValToSim;
    map<string, double> simPathToValFromSimMap; // the same map as indexFromXmlToValMap we just opposite the order
    map<int, string> indexFromXmlToValMap;  // int: 1 - 23 , string: the simulator strings
    void printXML();
    double getValue(string& s);
    void setValue(double d, string& s);
    string getPathByIndex(int i);
    bool isInList(string& s);
};

#endif //FLIGHTSIMULATOR_VAR_H
