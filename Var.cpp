//
// Created by adi on 15/12/2019.
//

#include "Var.h"
#include "string"
#include "map"
#include <sys/socket.h>
#include <cstring>

using namespace std;


void Var::updateVal(string newVal, map<string, Var*> varMap, map<string, Var*> simMap) {
    double doubleVal = stod(newVal);
    int socketfd;
    this->value = doubleVal;
    if (varUpdateSim) {
        //we need to update the var in the simulator to the new value
        string sim = this->sim;
        sim = sim.replace(sim.begin(), sim.end(),"sim(","");
        sim = sim.replace(sim.begin(), sim.end(),"\"","");
        sim = "set" + sim + newVal;
        int length = sim.length();
        char val [length+1];
        strcpy(val,sim.c_str());

        //writing back to client
        send(socketfd , val , strlen(val) , 0 );
    }
}

Var::Var(string name, double val, bool update, string sim1, string scope) {
    this->value = val;
    this->sim = sim;
    this->varName = std::move(name);
    this->varUpdateSim = update;
    this->scope = scope;
}
