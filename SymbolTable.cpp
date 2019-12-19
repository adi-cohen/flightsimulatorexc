//
// Created by adi on 16/12/2019.
//

#include "SymbolTable.h"
#include "Var.h"

using namespace std;


/* add a variable to the table by copy
void SymbolTable::addVariable(Var *v) {
    varMap[v->getName()] = v;
}
// get a pointer to a variable that is in the table
Var* SymbolTable::getVariable(string s) {
    if(isVariable(s)) {
        return reinterpret_cast<Var *>(&(varMap[s]));
    } else {
        return nullptr;
    }
}
// update the value of a variable that is in the table
void SymbolTable::updateVariable(string s, double d) {
    if(isVariable(s)) {
        ptrVarMap[s].setValue(d);
    } else {
        // no such variable error
        return;
    }
}
// check if a string is a name of a variable in the table
bool SymbolTable::isVariable(string s){
    if(ptrVarMap->find(s) != ptrVarMap->end()) {
        return true;
    } else {
        return false;
    }
}*/
