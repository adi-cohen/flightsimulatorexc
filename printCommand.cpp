#include <sstream>
#include "printCommand.h"
#include "iostream"
#include "SymbolTable.h"
#include "Interpreter.h"

//
// Created by yaron on 15/12/2019.
//
int printCommand::execute(vector<string> stringVector,SymbolTable *symTable, int index, int scope) {
    // put in varName the string "Print" without the "..."
    string varName = stringVector[index + 2];
    //int indexFirst = index;
    int startIndex = index + 2;
    int endLineIndex = index + 2;
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
        cout << calc << endl; // print value of the variable v1

    // means it's not a variable - should print the input without the ""
    } else {
        // iterate over the string vector until the string endLine
        while(stringVector[endLineIndex] != "endLine") {
            endLineIndex++;
        }
       for(int i = startIndex ; i < endLineIndex-1; i++) {
           cout << stringVector[i] << " ";
       }
       cout << " " << endl;
    }

    return endLineIndex + 1;
}

string printCommand::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}