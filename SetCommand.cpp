//
// Created by adi on 15/12/2019.
//

#include <sstream>
#include "SetCommand.h"
#include "Interpreter.h"

int SetCommend::execute(vector<string> stringVector,SymbolTable* symTable, int index, int scope) {
    string varName = stringVector[index];
    if (symTable->ptrVarMap->find(varName) != symTable->ptrVarMap->end()) {
        Var* v1 = (*symTable->ptrVarMap)[varName];
        //todo insert to equal command;
        index = index + 2;
        int endLineIndex = index + 1;
        while(stringVector[endLineIndex]!="endLine"){
            endLineIndex++;
        }
        string result = "";
        for(int i=index ; i<endLineIndex-index ; i++){
            result.append(stringVector[i]);
        }
        Interpreter* arithmeticInt = new Interpreter();
        //arithmeticInt -> setVariables();
        for (auto const& x : *symTable->ptrVarMap)
        {
            string var = x.first;
            string val = doubleToString(x.second->value);
            arithmeticInt->setVariables(var+"="+val);
        }
        //calculate the expression
        double calc = arithmeticInt->interpret(result)->calculate();
        // make a string from the double calculation
        string stringOfDoubleCalculation = doubleToString(calc);

        v1->updateVal(stringOfDoubleCalculation,symTable->ptrVarMap,symTable->ptrSimMap);
        return endLineIndex + 1;
    }
    else {
        throw "not valid command";
    }
}

string SetCommend::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}

