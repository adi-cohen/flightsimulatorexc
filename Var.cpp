//
// Created by adi on 15/12/2019.
//

#include "Var.h"
#include "string"
#include "map"
#include <sys/socket.h>
#include <cstring>

using namespace std;


void Var::updateVal(string newVal, SymbolTable *symTable) {
    double doubleVal = stod(newVal);
    int socketfd;
    this->value = doubleVal;
    if (varUpdateSim) {
        //we need to update the var in the simulator to the new value
        string sim1 = "set ";
        sim1.append(this->sim);
        sim1.append(" ");
        sim1.append(newVal);

        const char* val = sim1.c_str();

        //writing back to client
        //todo add the next line when the server working
        send(socketfd , val , strlen(val) , 0 );
    }
}
// getter
string Var::getName() {
    return varName;
}

Var::Var(string name1, double val, bool update, string sim1, int scope) {
    this->value = val;
    this->sim = sim1;
    this->varName = name1;
    this->varUpdateSim = update;
    this->scope = scope;
}

SymbolTable::SymbolTable(map<string, Var *> ptrVarMap1, map<string, Var *> ptrSimMap1) {
    this->simMap = ptrSimMap1;
    this->varMap = ptrVarMap1;
}