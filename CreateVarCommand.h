//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_CREATEVARCOMMAND_H
#define FLIGHTSIMULATOR_CREATEVARCOMMAND_H

#include <vector>
#include <string>
#include <map>
#include "Command.h"
#include "Var.h"

using namespace std;

class CreateVarCommand: public Command {
public:
    int execute(vector<string> stringVector,DataReaderServer *server, SymbolTable *symTable, int index, int scope);

    string doubleToString(double calc);
};

#endif //FLIGHTSIMULATOR_CREATEVARCOMMAND_H
