//
// Created by yaron on 16/12/2019.
//

#ifndef FLIGHTSIMULATOR_DATAXML_H
#define FLIGHTSIMULATOR_DATAXML_H
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

class DataXml {
    map<string, int> order;
public:
    DataXml();
    map<string, int>* getOrderXml();
};
#endif //FLIGHTSIMULATOR_DATAXML_H
