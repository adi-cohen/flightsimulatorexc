#include <sstream>
#include "printCommand.h"
#include "iostream"
#include "SymbolTable.h"
#include "Interpreter.h"

//
// Created by yaron on 15/12/2019.
//
int printCommand::execute(vector<string> strings,SymbolTable* symTable, int index, int scope) {
    /*index = index + 1;
    cout << strings[index] << endl;
    index = index + 1;
    return index;*/

        // make sure it is a variable/
        if (symTable->isVariable(strings[index + 1])) {
            string exp = strings[index + 1];
            Interpreter* arithmetic = new Interpreter();
            for (auto const& x : *symTable->ptrVarMap) {
                string var = x.first;
                string val = doubleToString(x.second->value);
                arithmetic->setVariables(var+"="+val);
            }
            double calc = arithmetic->interpret(exp)->calculate();
            //Var *v = symTable->getVariable(strings[0]);
            cout << calc << endl; // print his value
        } else { // print the input without the ""
            cout << strings[0].substr(1, strings[0].length() - 2) << endl;
        }

    return index + 2;
}

string printCommand::doubleToString(double calc)  {
    ostringstream stringStream;
    stringStream << calc;
    string stringOfDoubleCalculation = stringStream.str();
    return stringOfDoubleCalculation;
}