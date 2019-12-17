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

using namespace std;

vector<string> lexer(string fileName);

void parser(vector<string> vector);

int main(int argc, char *argv[]) {
    vector<string> stringVectorFromFile;
    string fileName = argv[1];
    //Parser* myParser;
    //insert the data from the file to the char vector
    try {
        stringVectorFromFile = lexer(fileName);
    } catch (const char *e) {
        cout << e << endl;
    }
    //todo - use the parser like this and not from the main
    //myParser->RunParser();
    // from lexer to parser
    parser(stringVectorFromFile);

    return 0;
}

void parser(vector<string> stringVector) {
    map<string, Var *> varMap; //from name to var.
    map<string, Var *> simMap; //from sim to var.
    map<string, Command *> commandMap;
    // insert command to map
    commandMap.insert(std::pair<string, Command *>("openDataServer", (new OpenDataServer())));
    commandMap["connectControlClient"] = (new ConnectClientCommand());
    commandMap["var"] = (new CreateVarCommand());
    //commandMap["Print"] = *(new PrintCommand());
    commandMap["Sleep"] = (new SleepCommand());


    int index = 0;
    //commandOfSimulatorMap.put()
    while (index != stringVector.size()) {
        string currentString = stringVector.at(index);
        //dealing with command
        //Check if its a command that exists in commandMap
        if (commandMap.find(currentString) != commandMap.end()) {
            //todo pass a pointer of the map to update them
            index = commandMap[currentString]->execute(stringVector, varMap, simMap, index);
        }
        else { //   dealing with update var val;
            (new SetCommend())->execute(stringVector, varMap, simMap, index);
        }
    }
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