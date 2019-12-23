//
// Created by adi on 15/12/2019.
//

#include "Var.h"
#include "string"
#include "map"
#include <sys/socket.h>
#include <cstring>
#include <iostream>


using namespace std;

void Var::updateVal(string newVal, SymbolTable *symTable) {
    
    double doubleVal = stod(newVal);
    int socketfd;
    this->value = doubleVal;
    if (varUpdateSim) {
        // we need to update the var in the simulator to the new value
        string sim1 = "set ";
        sim1.append(this->sim);
        sim1.append(" ");
        sim1.append(newVal);
        const char* val = sim1.c_str();
        //writing back to client
        //todo add the next line when the server working
        //add the value we need to update in the sim to the queue
        //we will update it in the connect command
        symTable->QueueSetValToSim.push(val);
    }
}
// getter
string Var::getName() {
    return varName;
}

// set the value of the variable to a new one
void Var::setValue(double d) {
    value = d;
}

Var::Var(string name1, double val, bool update, string sim1, int scope) {
    this->value = val;
    this->sim = sim1;
    this->varName = name1;
    this->varUpdateSim = update;
    this->scope = scope;
}

// Symbol Table implementations:
SymbolTable::SymbolTable(map<string, Var *> ptrVarMap1, map<string, Var *> ptrSimMap1) {
    this->simMap = ptrSimMap1;
    this->varMap = ptrVarMap1;
    indexFromXmlToValMap[1] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    indexFromXmlToValMap[2] = "/sim/time/warp";
    indexFromXmlToValMap[3] = "/controls/switches/magnetos";
    indexFromXmlToValMap[4] = "/instrumentation/heading-indicator/offset-deg";
    indexFromXmlToValMap[5] = "/instrumentation/altimeter/indicated-altitude-ft";
    indexFromXmlToValMap[6] = "/instrumentation/altimeter/pressure-alt-ft";
    indexFromXmlToValMap[7] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    indexFromXmlToValMap[8] = "/instrumentation/attitude-indicator/indicated-roll-deg";
    indexFromXmlToValMap[9] = "/instrumentation/attitude-indicator/internal-pitch-deg";
    indexFromXmlToValMap[10] = "/instrumentation/attitude-indicator/internal-roll-deg";
    indexFromXmlToValMap[11] = "/instrumentation/encoder/indicated-altitude-ft";
    indexFromXmlToValMap[12] = "/instrumentation/encoder/pressure-alt-ft";
    indexFromXmlToValMap[13] = "/instrumentation/gps/indicated-altitude-ft";
    indexFromXmlToValMap[14] = "/instrumentation/gps/indicated-ground-speed-kt";
    indexFromXmlToValMap[15] = "/instrumentation/gps/indicated-vertical-speed";
    indexFromXmlToValMap[16] = "/instrumentation/heading-indicator/indicated-heading-deg";
    indexFromXmlToValMap[17] = "/instrumentation/magnetic-compass/indicated-heading-deg";
    indexFromXmlToValMap[18] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    indexFromXmlToValMap[19] = "/instrumentation/turn-indicator/indicated-turn-rate";
    indexFromXmlToValMap[20] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    indexFromXmlToValMap[21] = "/controls/flight/aileron";
    indexFromXmlToValMap[22] = "/controls/flight/elevator";
    indexFromXmlToValMap[23] = "/controls/flight/rudder";
    indexFromXmlToValMap[24] = "/controls/flight/flaps";
    indexFromXmlToValMap[25] = "/controls/engines/engine/throttle";
    indexFromXmlToValMap[26] = "/controls/engines/current-engine/throttle";
    indexFromXmlToValMap[27] = "/controls/switches/master-avionics";
    indexFromXmlToValMap[28] = "/controls/switches/starter";
    indexFromXmlToValMap[29] = "/engines/active-engine/auto-start";
    indexFromXmlToValMap[30] = "/controls/flight/speedbrake";
    indexFromXmlToValMap[31] = "/sim/model/c172p/brake-parking";
    indexFromXmlToValMap[32] = "/controls/engines/engine/primer";
    indexFromXmlToValMap[33] = "/controls/engines/current-engine/mixture";
    indexFromXmlToValMap[34] = "/controls/switches/master-bat";
    indexFromXmlToValMap[35] = "/controls/switches/master-alt";
    indexFromXmlToValMap[36] = "/engines/engine/rpm";
    // initialize the simPathToValFromSimMap map with the string indexFromXmlToValMap.
    for(int i = 1; i <= 36; i++) {
        simPathToValFromSimMap[indexFromXmlToValMap[i]] = 0;
    }
}

// check if a string is a name of a variable in the table
bool SymbolTable::isVariable(string s){
    if(varMap.find(s) != varMap.end()) {
        return true;
    } else {
        return false;
    }
}

// update the value of a variable that is in the table
void SymbolTable::updateVariable(string s, double d) {
    if(isVariable(s)) {
        varMap[s]->setValue(d);
    } else {
        // no such variable error
        return;
    }
}

// get a pointer to a variable that is in the table
Var* SymbolTable::getVariable(string s) {
    if(isVariable(s)) {
        return *&(varMap[s]); // not sure about the syntax
    } else {
        return nullptr;
    }
}

// add a variable to the table by copy
void SymbolTable::addVariable(Var *v) {
    varMap[v->getName()] = v;
}

// new - update variable in the simMap
void SymbolTable::updateVariableInSimMap(string s, double d) {
    if(isVariableInSimMap(s)) {
        simMap[s]->setValue(d);
    } else {
        // no such variable error
        return;
    }
}
// new - check if it's a variable in the simMap
bool SymbolTable::isVariableInSimMap(string s) {
    if(simMap.find(s) != simMap.end()) {
        return true;
    } else {
        return false;
    }
}


// a test function for printing
void SymbolTable::printXML() {
    for(int i = 1; i <= 36 ; i++) {
        std::cout << simPathToValFromSimMap[indexFromXmlToValMap[i]];
        cout << ",";
    }
    cout << endl;
}
// get a value from the map only if the strings is correct
double SymbolTable::getValue(string& s) {
    if(simPathToValFromSimMap.find(s) != simPathToValFromSimMap.end()) { // make sure the strings is in
        return simPathToValFromSimMap[s]; // return the value of this string
    } else{
        //throw value not in simulator error
        return 0;
    }
}
// set a new value for a string in the server
void SymbolTable::setValue(double d, string& s) {
    simPathToValFromSimMap[s] = d;
}
// get a strings from the number of position in the xml
string SymbolTable::getPathByIndex(int i) {
    return indexFromXmlToValMap[i];
}
// check if a string is in out list of strings/
bool SymbolTable::isInList(string& s) {
    if(simPathToValFromSimMap.find(s) == simPathToValFromSimMap.end()) {
        return false;
    } else {
        return true;
    }
}