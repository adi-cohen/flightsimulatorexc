//
// Created by yaron on 13/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "SleepCommand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <thread>

int SleepCommand::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {
    index = index + 1;
    //if(stringVector.size() != 1) {
   //     //error in number of parameters
    //    return -1;
    //}
    // save the number that was inputed
    int milis = stoi(stringVector[index]);
    // sleep command
    //todo fix the next line - its return error
//    std::this_thread::sleep_for(std::chrono::milliseconds(milis));
    index = index + 2;
    return index;
}
