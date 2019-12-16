#include <sstream>
#include "Command.h"
#include "whileCommand.h"
#include "Interpreter.h"


//
// Created by yaron on 15/12/2019.
//
int whileCommand::execute(vector<string> strings, map<string, Var *> varMap, map<string, Var *> simMap, int index) {
    int indexFindOperator;
    int indexSulSul;
    int whileIndex = index;

    // run over the first line of the while until the {
    while(strings[index] != "{") {
        if(isOperator(strings[index])) {
                indexFindOperator = index;
        }
        index++;
    }
    indexSulSul = index;

    string expLeft = "";
    string expRight = "";
    // for the left expression
    for(int i = whileIndex + 1 ; i < indexFindOperator - 1 ; i++){
        expLeft.append(strings[i]);
    }
    // for the right expression
    for(int j = indexFindOperator + 1 ; j < indexSulSul - 1; j++) {
        expRight.append(strings[j]);
    }

    Interpreter* arithmeticLeft = new Interpreter();
    Interpreter* arithmeticRight = new Interpreter();

    for (auto const& x : varMap)
    {
        string var = x.first;
        string val = doubleToString(x.second->value);
        arithmeticLeft->setVariables(var+"="+val);
    }

    for (auto const& y : varMap)
    {
        string var = y.first;
        string val = doubleToString(y.second->value);
        arithmeticRight->setVariables(var+"="+val);
    }


}

bool whileCommand::isOperator(string s) {
    if (s.compare("<") == 0) { return true; }
    else if (s.compare(">") == 0) { return true; }
    else if (s.compare("<=") == 0) { return true; }
    else if (s.compare(">=") == 0) { return true; }
    else if (s.compare("=>") == 0) { return true; }
    else if (s.compare("=<") == 0) { return true; }
    else if (s.compare("=") == 0) { return true; }
}

string whileCommand::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}