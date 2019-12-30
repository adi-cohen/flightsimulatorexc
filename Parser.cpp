//
// Created by adi on 16/12/2019.
//

#include "Parser.h"
#include "OpenDataServer.h"
#include "ConnectClientCommand.h"
#include "CreateVarCommand.h"
#include "SleepCommand.h"
#include "vector"
#include "SetCommand.h"
#include "printCommand.h"
#include "whileCommand.h"



void Parser::RunParser() {

    map<string, Command *> commandMap;
    // insert command to map
    commandMap["openDataServer"] = (new OpenDataServer());
    commandMap["connectControlClient"] = (new ConnectClientCommand());
    commandMap["var"] = (new CreateVarCommand());
    commandMap["Print"] = (new printCommand());
    commandMap["Sleep"] = (new SleepCommand());
    commandMap["while"] = (new whileCommand());

    unsigned int currentIndex = this->index;
    //commandOfSimulatorMap.put()
    while (currentIndex != stringVector.size()) {
        string currentString = stringVector.at(currentIndex);
        //dealing with command
        //Check if its a command that exists in commandMap
        if (commandMap.find(currentString) != commandMap.end()) {
            try {
                currentIndex = commandMap[currentString]->execute(stringVector, symbolTable, currentIndex);
            }
            catch (const char *e) {
                cout << e << endl;
            }
        } else { //   dealing with update var val;
            currentIndex = (new SetCommand())->execute(stringVector, symbolTable, currentIndex);
            cout << currentString << endl;
        }
    }
}

Parser::Parser(vector<string> stringVector1,
               SymbolTable *symbolTable1, int index1) {
    this->symbolTable = symbolTable1;
    this->stringVector = stringVector1;
    this->index = index1;
}

