//
// Created by yaron on 14/12/2019.
//
#include "SymbolTable.h"
// add a variable to the table by copy
void SymbolTable::addVariable(variable v) {
    variables[v.myName()] = v;
}

