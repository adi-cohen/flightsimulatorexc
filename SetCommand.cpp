//
// Created by adi on 15/12/2019.
//

#include <sstream>
#include "SetCommand.h"
#include "Interpreter.h"

int SetCommend::execute(vector<string> stringVector, map<string, Var*> varMap, map<string, Var*> simMap, int index) {
    string varName = stringVector[index];
    if (varMap.find(varName) != varMap.end()) {
        Var* v1 = varMap[varName];
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
        for (auto const& x : varMap)
        {
            string var = x.first;
            string val = doubleToString(x.second->value);
            arithmeticInt->setVariables(var+"="+val);
        }
        //calculate the expression
        double calc = arithmeticInt->interpret(result)->calculate();
        // make a string from the double calculation
        string stringOfDoubleCalculation = doubleToString(calc);
        v1->updateVal(stringOfDoubleCalculation,varMap,simMap);
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

