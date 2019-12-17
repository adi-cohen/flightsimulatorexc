#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-slicing"
#pragma ide diagnostic ignored "hicpp-use-auto"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include "Command.h"
#include "OpenDataServer.h"
#include "SleepCommand.h"
#include "Var.h"
#include "SetCommand.h"
#include "Interpreter.h"
#include "Expression.h"
#include "ConnectClientCommand.h"
#include "CreateVarCommand.h"
#include "Parser.h"
#include "printCommand.h"

using namespace std;

vector<string> lexer(string fileName);

void parser(vector<string> vector);

int main(int argc, char *argv[]) {
    //string x ;
    vector<string> stringVectorFromFile;
    string fileName = argv[1];
    //insert the data from the file to the char vector
    try {
        stringVectorFromFile = lexer(fileName);
    } catch (const char *e) {
        cout << e << endl;
    }
    // from lexer to parser
    map<string, Var *> varMap; //from name to var.
    map<string, Var *> simMap; //from sim to var.
    map<string, Command *> commandMap;
    // insert command to map
    commandMap.insert(std::pair<string, Command *>("openDataServer", (new OpenDataServer())));
    commandMap["connectControlClient"] = (new ConnectClientCommand());
    commandMap["var"] = (new CreateVarCommand());
    commandMap["Print"] = (new printCommand());
    commandMap["Sleep"] = (new SleepCommand());
    int mainScope =0;
    SymbolTable* mainSymbolTable = new SymbolTable(varMap,simMap);
    Parser* mainParser = new Parser(stringVectorFromFile,mainSymbolTable,0,mainScope);
    mainParser->RunParser();
    return 0;
}


vector<string> lexer(string fileName) {
    vector<string> charArray;
    ifstream file;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        throw "can not find file";
    }
    string word;

    std::string line;
    while (std::getline(file, line)) {
        istringstream iss(line);
        while (iss >> word) {
            //if the word contains ( or ) we need to split it
            if ((word.find("(") < word.size())
                | (word.find(")") < word.size())) {
                string splitWord = "";
                for (auto x :word) {
                    if ((x == '(') || x == ')') {
                        charArray.push_back(splitWord);
                        splitWord = "";
                    } else {
                        splitWord = splitWord + x;
                    }
                }
                //charArray.push_back(splitWord);
                splitWord = "";
            } else {
                charArray.push_back(word);
            }
        }
        charArray.push_back("endLine");
    }
    file.close();
    return charArray;
}


#pragma clang diagnostic pop