#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include<iterator>
#include "Command.h"
#include "OpenDataServer.h"
#include "Parser.h"
#include "SleepCommand.h";openDataServer(5400)
#include "Var.h";

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
    parser(stringVectorFromFile);

    return 0;
}

void parser(vector<string> stringVector) {
    map<string, Var*> varMap; //from name to var
    map<string, Var*> simMap; //from sim to var

    map<string, Command> commandMap;

    int index = 0;
    //commandOfSimulatorMap.put()
    while (index != stringVector.size()) {
        string currentString = stringVector.at(index);
        //dealing with command
        //Check if its a command that exists in commandMap
        if (commandMap.find(currentString) != commandMap.end()) {
            //todo ask about the vector that we pass to execute
            index = commandMap[currentString].execute(stringVector, varMap, simMap, index);
        }
            //dealing with update var val;
        else if (varMap.find(currentString) != varMap.end()) {
            index = index + 2;
            string newVal = stringVector.at(index);
            double doubleVal = stod(newVal);
            varMap[currentString].updateVal(doubleVal, varMap,simMap);
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
    while (file >> word) {
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
    file.close();
    return charArray;
}




