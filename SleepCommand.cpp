//
// Created by yaron on 13/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "SleepCommand.h"
#include "Interpreter.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <thread>

int SleepCommand::execute(vector<string> stringVector, SymbolTable *symTable, int index) {
    index = index + 2;
    // put in varName the string Sleep without the
    string varName = stringVector[index];
    //int indexFirst = index;
    int startIndex = index;
    int endLineIndex = index;
    // verify that it's a correct variable in the varMap
    if (symTable->varMap.find(varName) != symTable->varMap.end()) {
        // iterate over the string vector until the string endLine
        while(stringVector[endLineIndex] != "endLine") {
            endLineIndex++;
        }
        // the string result will holds the expression we would like to print
        string result = "";
        for(int i = startIndex ; i < endLineIndex-1 ; i++) {
            result.append(stringVector[i]);
        }

        Interpreter* arithmeticInt = new Interpreter();
        // the following loop inserts the simPathToValFromSimMap from the varMap of our symTable
        // inside the varaibles of the interpreter
        for (auto const& x : symTable->varMap) {
            string var = x.first;
            string val = doubleToString(x.second->value);
            arithmeticInt->setVariables(var + "=" + val);
        }

        double calc = arithmeticInt->interpret(result)->calculate();
        string stringOfDoubleCalculation = doubleToString(calc);
        //int milis = stoi(stringOfDoubleCalculation);
        int res = calc;
        //cout << res << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(res));
        return endLineIndex + 1;

    // means it's not a variable
    } else {
        // save the number that was inputed
        int milis = stoi(stringVector[index]);
        // sleep command
        //todo fix the next line - its return error
        std::this_thread::sleep_for(std::chrono::milliseconds(milis));
        index = index + 3;
        return index;
    }

}


string SleepCommand::doubleToString(double calc) {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}

