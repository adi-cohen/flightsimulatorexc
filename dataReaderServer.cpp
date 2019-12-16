//
// Created by yaron on 16/12/2019.
//
#include "SymbolTable.h"
#include "Var.h"
#include "dataReaderServer.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>


DataReaderServer::DataReaderServer() {
    // map all of the strings of variables to numbers
    names[1] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    names[2] = "/instrumentation/altimeter/indicated-altitude-ft";
    names[3] = "/instrumentation/altimeter/pressure-alt-ft";
    names[4] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    names[5] = "/instrumentation/attitude-indicator/indicated-roll-deg";
    names[6] = "/instrumentation/attitude-indicator/internal-pitch-deg";
    names[7] = "/instrumentation/attitude-indicator/internal-roll-deg";
    names[8] = "/instrumentation/encoder/indicated-altitude-ft";
    names[9] = "/instrumentation/encoder/pressure-alt-ft";
    names[10] = "/instrumentation/gps/indicated-altitude-ft";
    names[11] = "/instrumentation/gps/indicated-ground-speed-kt";
    names[12] = "/instrumentation/gps/indicated-vertical-speed";
    names[13] = "/instrumentation/heading-indicator/indicated-heading-deg";
    names[14] = "/instrumentation/magnetic-compass/indicated-heading-deg";
    names[15] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    names[16] = "/instrumentation/turn-indicator/indicated-turn-rate";
    names[17] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    names[18] = "/controls/flight/aileron";
    names[19] = "/controls/flight/elevator";
    names[20] = "/controls/flight/rudder";
    names[21] = "/controls/flight/flaps";
    names[22] = "/controls/engines/current-engine/throttle";
    names[23] = "/engines/engine/rpm";
    // initialize the values map with the string names.
    for(int i = 1; i <= 23; i++) {
        values[names[i]] = 0;
    }

    // set a new value for a string in the server
    void DataReaderServer::setValue(double d, string& s) {
        values[s] = d;
    }
    // check if a string is in out list of strings/
    bool DataReaderServer::isInList(string& s) {
        if(values.find(s) == values.end()) {
            return false;
        } else {
            return true;
        }
    }
}
