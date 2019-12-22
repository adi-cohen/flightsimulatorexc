//
// Created by yaron on 16/12/2019.
//
#include "SymbolTable.h"
#include "Var.h"
#include "DataReaderServer.h"
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
#include "DataReaderServer.h"
#include "DataReaderServer.h"
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


DataReaderServer ::DataReaderServer() {
    // map all of the strings of variables to numbers
    names[1] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    names[2] = "/sim/time/warp";
    names[3] = "/controls/switches/magnetos";
    names[4] = "/instrumentation/heading-indicator/offset-deg";
    names[5] = "/instrumentation/altimeter/indicated-altitude-ft";
    names[6] = "/instrumentation/altimeter/pressure-alt-ft";
    names[7] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    names[8] = "/instrumentation/attitude-indicator/indicated-roll-deg";
    names[9] = "/instrumentation/attitude-indicator/internal-pitch-deg";
    names[10] = "/instrumentation/attitude-indicator/internal-roll-deg";
    names[11] = "/instrumentation/encoder/indicated-altitude-ft";
    names[12] = "/instrumentation/encoder/pressure-alt-ft";
    names[13] = "/instrumentation/gps/indicated-altitude-ft";
    names[14] = "/instrumentation/gps/indicated-ground-speed-kt";
    names[15] = "/instrumentation/gps/indicated-vertical-speed";
    names[16] = "/instrumentation/heading-indicator/indicated-heading-deg";
    names[17] = "/instrumentation/magnetic-compass/indicated-heading-deg";
    names[18] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    names[19] = "/instrumentation/turn-indicator/indicated-turn-rate";
    names[20] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    names[21] = "/controls/flight/aileron";
    names[22] = "/controls/flight/elevator";
    names[23] = "/controls/flight/rudder";
    names[24] = "/controls/flight/flaps";
    names[25] = "/controls/engines/engine/throttle";
    names[26] = "/controls/engines/current-engine/throttle";
    names[27] = "/controls/switches/master-avionics";
    names[28] = "/controls/switches/starter";
    names[29] = "/engines/active-engine/auto-start";
    names[30] = "/controls/flight/speedbrake";
    names[31] = "/sim/model/c172p/brake-parking";
    names[32] = "/controls/engines/engine/primer";
    names[33] = "/controls/engines/current-engine/mixture";
    names[34] = "/controls/switches/master-bat";
    names[35] = "/controls/switches/master-alt";
    names[36] = "/engines/engine/rpm";
    // initialize the values map with the string names.
    for(int i = 1; i <= 36; i++) {
        values[names[i]] = 0;
    }
}
// a test function for printing
void DataReaderServer::printXML() {
    for(int i = 1; i <= 36 ; i++) {
       cout<< values[names[i]];
       cout << ",";
    }
    cout << endl;
}
// get a value from the map only if the strings is correct
double DataReaderServer::getValue(string& s) {
    if(values.find(s) != values.end()) { // make sure the strings is in
        return values[s];
    } else{
        //throw value not in simulator error
        return 0;
    }
}
// set a new value for a string in the server
void DataReaderServer::setValue(double d, string& s) {
    values[s] = d;
}
// get a strings from the number of position in the xml
string DataReaderServer::getPathByIndex(int i) {
    return names[i];
}
// check if a string is in out list of strings/
bool DataReaderServer::isInList(string& s) {
    if(values.find(s) == values.end()) {
        return false;
    } else {
        return true;
    }
}

