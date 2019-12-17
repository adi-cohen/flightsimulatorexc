//
// Created by adi on 16/12/2019.
//

#include "SymbolTable.h"
using namespace std;

SymbolTable::SymbolTable(map<string, Var *> *ptrVarMap1, map<string, Var *> *ptrSimMap1, int scope1, int index1) {
    this->scope=scope1;
    this->index=index1;
    this->ptrSimMap =ptrSimMap1;
    this->ptrVarMap = ptrVarMap1;
}

// add a variable to the table by copy
void SymbolTable::addVariable(Var v) {
    //ptrVarMap[v.getName()] = v;
}
// get a pointer to a variable that is in the table
Var* SymbolTable::getVariable(string s) {
    if(isVariable(s)) {
        //return &(ptrVarMap[s]);
    } else {
        return nullptr;
    }
}
// update the value of a variable that is in the table
void SymbolTable::updateVariable(string s, double d) {
    if(isVariable(s)) {
        //ptrVarMap[s].setValue(d);
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
}
