//
// Created by yaron on 18/12/2019.
//

#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H

#include "Command.h"
#include "Interpreter.h"

class ifCommand : public Command {
public:
    int execute(vector<string> stringVector,DataReaderServer *server, SymbolTable *symTable, int index, int scope);
    bool isOperator(string s);
    string doubleToString(double calc);
    int isOperatorFlag(string s);
    void updateVarMap(const SymbolTable *symTable, const string &expLeft, const string &expRight,
                      Interpreter *arithmeticLeft,
                      Interpreter *arithmeticRight);
};
        #endif //FLIGHTSIMULATOR_IFCOMMAND_H
