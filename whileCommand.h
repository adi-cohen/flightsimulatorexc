//
// Created by yaron on 15/12/2019.
//

#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include "Interpreter.h"

class whileCommand : public Command {
public:
    int execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope);
    bool isOperator(string s);
    string doubleToString(double calc);
    int isOperatorFlag(string s);
    void updateVarMap(const SymbolTable *symTable, const string &expLeft, const string &expRight,
                      Interpreter *arithmeticLeft,
                      Interpreter *arithmeticRight);
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H