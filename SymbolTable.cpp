//
// Created by adi on 16/12/2019.
//

#include "SymbolTable.h"
using namespace std;

SymbolTable::SymbolTable(map<string, Var *> *ptrVarMap1, map<string, Var *> *ptrSimMap1) {
    this->ptrSimMap =ptrSimMap1;
    this->ptrVarMap = ptrVarMap1;
}

