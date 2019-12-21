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

// set the value of the vriable to a new one
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

// todo - new for threads
/* bind a variable to a string
void Var::bind(string s) {
    if (table->isVariable(s)) { // if the string is a variable name
        isServer = false;
        isVar = true;
    } else { // the string should be a server path
        isServer = true;
        isVar = false;
    }
    // bind us to this
    bindTo = s;
    // update the table that we are bounded
    table->bindVariable(this->name, s);
}
// calculate the value of the variable
double Var::calculate() {
    if(isVar) { // our variable is binded to another
        value = (table->getVariable(bindTo))->calculate();
    } else if(isServer) { // our variable is binded to simulator value
        value = server->getValue(bindTo);
    }
    return value;
}
// set the value of the vriable to a new one
void Var::setValue(double d) {
    value = d;
}

void Var::setOnlyBind(string s) {
    this->bindTo = s;
    this->setBind = true;
}*/