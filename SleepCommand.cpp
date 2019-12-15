//
// Created by yaron on 13/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "SleepCommand.h"
#include <thread>

int SleepCommand::execute(vector<string> strings,map<string, Var*> varMap, map<string, Var*> simMap, int index) {
    if(strings.size() != 1) {
        //error in number of parameters
        return -1;
    }
    // save the number that was inputed
    int milis = stoi(strings[0]);
    // sleep command
    std::this_thread::sleep_for(std::chrono::milliseconds(milis));
    return true;
}
