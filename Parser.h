//
// Created by adi on 12/12/2019.
//

#ifndef FLIGHTSIMULATOR_PARSER_H
#define FLIGHTSIMULATOR_PARSER_H

#include "Command.h"
#include "Var.h"
#include "SymbolTable.h"
#include "map"
#include "string"
#include "vector"
using namespace std;

class Parser {
    SymbolTable* symbolTable;
    vector<string> stringVector;
public:
    Parser( vector<string> stringVector1, SymbolTable* symbolTable);
    void RunParser();

};

#endif //FLIGHTSIMULATOR_PARSER_H
