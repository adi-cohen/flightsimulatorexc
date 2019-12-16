#include "printCommand.h"
#include "iostream"
//
// Created by yaron on 15/12/2019.
//
int printCommand :: execute(vector<string> strings, map<string, Var*> varMap, map<string, Var*> simMap, int index) {
    index = index + 1;
    cout << strings[index] << endl;
    index = index + 1;
    return index;
}
