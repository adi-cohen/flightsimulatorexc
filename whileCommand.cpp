#include <sstream>
#include "Command.h"
#include "whileCommand.h"
#include "Interpreter.h"
#include "Parser.h"
#include "SymbolTable.h"


//
// Created by yaron on 15/12/2019.
//
int whileCommand::execute(vector<string> strings,SymbolTable* symTable, int index, int scope) {
    int indexFindOperator;
    int indexSulSul;
    int indexCloseSulSul;
    int whileIndex = index;
    string isOper = "";

    // run over the first line of the while until the {
    while(strings.at(index) != "{") {
        if(isOperator(strings.at(index))) {
                indexFindOperator = index;
                isOper = strings.at(indexFindOperator);
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

    for (auto const& x : *symTable->ptrVarMap) {
        string var = x.first;
        string val = doubleToString(x.second->value);
        arithmeticLeft->setVariables(var+"="+val);
        arithmeticRight->setVariables(var+"="+val);
    }


    // first we calculate each expression
    double calcLeft = arithmeticLeft->interpret(expLeft)->calculate();
    double calcRight = arithmeticRight->interpret(expRight)->calculate();
    int sign = isOperatorFlag(isOper);

    vector<string> whileVector;
    int j = indexSulSul + 1;
    while(strings.at(j) != "}") {
        whileVector.push_back(strings.at(j));
        j++;
    }
    indexCloseSulSul = j;

    // check if the condition of the while is true
    switch (sign) { ;
        case 1:
            while (calcLeft < calcRight) {
                // call parser
                Parser *whileParser = new Parser(whileVector, symTable, index, scope + 1);
                updateVarMap(symTable, expLeft, expRight, arithmeticLeft, arithmeticRight);
            }
            break;
        case 2:
            while (calcLeft > calcRight) {
                // call parser
                Parser* whileParser = new Parser(whileVector, symTable, index, scope + 1);
                updateVarMap(symTable, expLeft, expRight, arithmeticLeft, arithmeticRight);
            }
            break;
        case 3:
            while (calcLeft <= calcRight) {
                // call parser
                Parser *whileParser = new Parser(whileVector, symTable, index, scope + 1);
                updateVarMap(symTable, expLeft, expRight, arithmeticLeft, arithmeticRight);
            }
            break;
        case 4:
            while (calcLeft >= calcRight) {
                // call parser
                Parser* whileParser = new Parser(whileVector, symTable, index, scope + 1);
                updateVarMap(symTable, expLeft, expRight, arithmeticLeft, arithmeticRight);
            }
            break;
        case 5:
            while (calcLeft == calcRight) {
                // call parser
                Parser* whileParser = new Parser(whileVector, symTable, index, scope + 1);
                updateVarMap(symTable, expLeft, expRight, arithmeticLeft, arithmeticRight);
            }
            break;
        case 6:
            while (calcLeft != calcRight) {
                // call parser
                Parser* whileParser = new Parser(whileVector, symTable, index, scope + 1);
                updateVarMap(symTable, expLeft, expRight, arithmeticLeft, arithmeticRight);
            }
            break;
    }

    return indexCloseSulSul+2;
}

void whileCommand::updateVarMap(const SymbolTable *symTable, const string &expLeft, const string &expRight,
                                Interpreter *arithmeticLeft, Interpreter *arithmeticRight) {
    for (auto const &x : *symTable->ptrVarMap) {
        string var = x.first;
        string val = doubleToString(x.second->value);
        arithmeticLeft->setVariables(var + "=" + val);
        arithmeticRight->setVariables(var + "=" + val);
    }
    // inside the while loop
    double calcLeft = arithmeticLeft->interpret(expLeft)->calculate();
    double calcRight = arithmeticRight->interpret(expRight)->calculate();
}

int whileCommand::isOperatorFlag(string s) {
    if (s.compare("<") == 0) { return 1; }
    else if (s.compare(">") == 0) { return 2; }
    else if (s.compare("<=") == 0) { return 3; }
    else if (s.compare(">=") == 0) { return 4; }
    else if (s.compare("==") == 0) { return 5; }
    else if(s.compare("!=") == 0 ){ return 6; }
}

bool whileCommand::isOperator(string s) {
    if (s.compare("<") == 0) { return true; }
    else if (s.compare(">") == 0) { return true; }
    else if (s.compare("<=") == 0) { return true; }
    else if (s.compare(">=") == 0) { return true; }
    //else if (s.compare("=>") == 0) { return true; }
    //else if (s.compare("=<") == 0) { return true; }
    else if (s.compare("=") == 0) { return true; }
    else if(s.compare("!=") == 0 ){ return true;  }
}

string whileCommand::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}