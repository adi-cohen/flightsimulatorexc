//
// Created by adi on 15/12/2019.
//

#include <sstream>
#include <mutex>
#include "SetCommand.h"
#include "Interpreter.h"

int SetCommand::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {
    string varName = stringVector[index];
    if (symTable->varMap.find(varName) != symTable->varMap.end()) {
        Var* v1 = (symTable->varMap)[varName];
        index = index + 2;
        int endLineIndex = index + 1;
        while(stringVector[endLineIndex]!="endLine"){
            endLineIndex++;
        }
        string result = "";
        for(int i=index ; i<endLineIndex ; i++){
            result.append(stringVector[i]);
        }
        Interpreter* arithmeticInt = new Interpreter();
        for (auto const& x : symTable->varMap)
        {
            string var = x.first;
            string val = doubleToString(x.second->value);
            arithmeticInt->setVariables(var+"="+result);
        }
        //calculate the expression
        double calc = arithmeticInt->interpret(result)->calculate();
        // make a string from the double calculation
        string stringOfDoubleCalculation = doubleToString(calc);
        v1->updateVal(stringOfDoubleCalculation,symTable);;
        return endLineIndex + 1;
    }
    else {
        throw "not valid command";
    }
}

string SetCommand::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}

