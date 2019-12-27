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
#include <mutex>
#include "SymbolTable.h"

class SymbolTable;
//class DataReaderServer;
using namespace std;

class Var {
public:
    bool varUpdateSim;
    string sim;
    int scope;

    string varName;
    double value;

    //todo not sure we need the constructor because of the update function
    Var(string name, double val, bool update, string sim1, int scope1);

};

class SymbolTable {
public:
    map<string, Var *> varMap;
    map<string, Var *> simMap;
    std::mutex mutex;

    SymbolTable(map<string, Var *> ptrVarMap, map<string, Var *> ptrSimMap);

    queue<string> QueueSetValToSim;
    map<string, double> simPathToValFromSimMap; // the same map as indexFromXmlToValMap we just opposite the order
    map<int, string> indexFromXmlToValMap;  // int: 1 - 36 , string: the simulator strings
    void printXML();

};

#endif //FLIGHTSIMULATOR_VAR_H
