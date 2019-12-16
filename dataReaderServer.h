//
// Created by yaron on 16/12/2019.
//

#ifndef FLIGHTSIMULATOR_DATAREADERSERVER_H
#define FLIGHTSIMULATOR_DATAREADERSERVER_H
#include <map>
#include <string>
#include <exception>
#include <sstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <thread>
//#include "symbolTable.h"
using namespace std;
class symbolTable;
class DataReaderServer {
private:
    map<string, double> values;
    map<int, string> names;
public:
    DataReaderServer();
    double getValue(string& s);
    void setValue(double d, string& s);
    string getStringFromXMlLocation(int i);
    bool isInList(string& s);
};
void updateVals(int newsockfd, int timesPerSecond, DataReaderServer* reader,
                symbolTable* table);
#endif //FLIGHTSIMULATOR_DATAREADERSERVER_H
