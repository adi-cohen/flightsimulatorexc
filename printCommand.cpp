#include "printCommand.h"
#include "iostream"
//
// Created by yaron on 15/12/2019.
//
int printCommand :: execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope) {
    index = index + 1;
    cout << stringVector[index] << endl;
    index = index + 1;
    return index;
}
