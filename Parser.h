//
// Created by adi on 12/12/2019.
//

#ifndef FLIGHTSIMULATOR_PARSER_H
#define FLIGHTSIMULATOR_PARSER_H

#include "Command.h"
#include "Var.h"
#include "SymbolTable.h"
#include "DataXml.h"
#include "map"
#include "string"
#include "vector"
using namespace std;

class Parser {
    SymbolTable* symbolTable;
    vector<string> stringVector;
    int index;
    int scope;
    bool flightGearRunning;
    bool closeServer;
    DataXml dataXml;

public:
    Parser(vector<string> stringVector1, SymbolTable* symbolTable,int index,int scope);
    void RunParser();
    bool signalFlightGearRunning(bool mode);
    bool checkServerClose();
    map<string, int> *getDataXml();
};

#endif //FLIGHTSIMULATOR_PARSER_H
