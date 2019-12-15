//
// Created by adi on 15/12/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "CreateVarCommand.h"
#include <sstream>
#include "map"
#include "Var.h"
#include "Interpreter.h"



int CreateVarCommand::execute(vector<string> stringVector, map<string, Var *> varMap, map<string, Var *> simMap,
                              int index) {
    index = index + 1;
    string varName = stringVector.at(index);
    index = index + 1;
    string op = stringVector.at(index);
    if (op == "="){
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
        Var *newVar = new Var(varName, calc, false, "", "");
        varMap.insert({varName,newVar});
        return endLineIndex + 1;
    }
    index = index + 2;
    string simVal = stringVector.at(index);
    if (op == "->") {
        Var *newVar = new Var(varName, 0, true, simVal, "");
        //the app need to update the simulator
        varMap.insert({varName, newVar});
        index = index + 2;
        return index;
    } else if (op == "<-") {
        Var *newVar = new Var(varName, 0, false, simVal, "");
        //the simulator need to update the app
        simMap.insert({simVal, newVar});
        varMap.insert({varName, newVar});
        index = index + 2;
        return index;
    }

}

string CreateVarCommand::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}