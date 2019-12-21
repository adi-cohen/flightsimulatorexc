//
// Created by yaron on 13/12/2019.
//

#ifndef FLIGHTSIMULATOR_OPENDATASERVER_H
#define FLIGHTSIMULATOR_OPENDATASERVER_H

#include <vector>
#include <string>
#include "Command.h"
#include "DataReaderServer.h"

using namespace std;
class OpenDataServer: public Command {
public:
    int execute(vector<string> stringVector, DataReaderServer *server, SymbolTable *symTable, int index, int scope);
};

#endif //FLIGHTSIMULATOR_OPENDATASERVER_H
