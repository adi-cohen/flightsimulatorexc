//
// Created by yaron on 14/12/2019.
//
#include "symbolTable.h"
// add a variable to the table by copy
void symbolTable::addVariable(variable v) {
    variables[v.myName()] = v;
}

