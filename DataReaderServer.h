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

using namespace std;
#include <map>
using namespace std;
class SymbolTable;
class DataReaderServer {
private:
    map<string, double> simPathToValFromSimMap; // the same map as indexFromXmlToValMap we just opposite the order
    map<int, string> indexFromXmlToValMap;  // int: 1 - 23 , string: the simulator strings
public:
    DataReaderServer();
    void printXML();
    double getValue(string& s);
    void setValue(double d, string& s);
    string getPathByIndex(int i);
    bool isInList(string& s);
};
// The static method
void updateVals(int simulatorClient, int timesPerSecond, DataReaderServer *reader, SymbolTable* table);

#endif //FLIGHTSIMULATOR_DATAREADERSERVER_H
