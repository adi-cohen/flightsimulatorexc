//
// Created by adi on 29/12/2019.
//

#include <algorithm>
#include "runFunctionCommand.h"
#include "string"
#include "Parser.h"

int runFunctionCommand::execute(vector<string> stringVector, SymbolTable *symTable, int index, int scope) {
    string functionName = stringVector.at(index);
    string FunctionVarValue = stringVector.at(index + 2);
    vector<string> functionVector = symTable->functionMap[functionName];
    int varIndex = 0;
    while (functionVector.at(varIndex) != "var") {
        varIndex += 1;
    }
    string functionVarName = functionVector.at(varIndex + 1);
    replace(functionVector.begin(), functionVector.end(), functionVarName, FunctionVarValue);
    int openingIndex = 0;
    int closingIndex = 0;
    int numOfStartParenthesis = 1;
    int numOfEndParenthesis = 0;
    while (functionVector.at(openingIndex) != "{") {
        openingIndex += 1;
    }

    closingIndex = openingIndex + 1;
    while (numOfStartParenthesis != numOfEndParenthesis) {
        if (functionVector.at(closingIndex) == "{") {
            numOfStartParenthesis += 1;
        }
        if (functionVector.at(closingIndex) == "}") {
            numOfEndParenthesis += 1;
        }
        closingIndex += 1;;
    }
    vector<string> vectorForParser;
    for (int i = openingIndex+2; i <= closingIndex-2; i++) {
        vectorForParser.push_back(functionVector.at(i));
    }
    Parser *functionParser = new Parser(vectorForParser, symTable, 0, scope + 1);
    functionParser->RunParser();
    return index + 5;
}

