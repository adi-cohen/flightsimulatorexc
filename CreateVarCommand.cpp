//
// Created by adi on 15/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "CreateVarCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map"
#include "Var.h"


int CreateVarCommand::execute(vector<string> stringVector, map<string, Var *> varMap, map<string, Var *> simMap,
                              int index) {
    index = index + 1;
    string varName = stringVector.at(index);
    index = index + 1;
    string direction = stringVector.at(index);
    index = index + 1;
    string simVal = stringVector.at(index);
    if (direction == "->") {
        Var *newVar = new Var(varName, 0, true, simVal, NULL);
        //the app need to update the simulator
        varMap.insert({varName, newVar});
    } else if (direction == "<-") {
        Var *newVar = new Var(varName, 0, false, simVal, NULL);
        //the simulator need to update the app
        simMap.insert({simVal, newVar});
        varMap.insert({varName, newVar});
    }
    index = index + 1;
    return index;
}
