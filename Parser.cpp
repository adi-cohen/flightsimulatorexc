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


//void parser(vector<string> stringVector) {


//Parser::Parser(SymbolTable symTable, vector<string> stringVector1) {
//    this->symbolTable = symTable;
//    this->stringVector = stringVector1;
//
//}

void Parser::RunParser() {

    map<string, Command *> commandMap;
    // insert command to map
    commandMap["openDataServer"] = (new OpenDataServer());
    commandMap["connectControlClient"] = (new ConnectClientCommand());
    commandMap["var"] = (new CreateVarCommand());
    commandMap["Print"] = (new printCommand());
    commandMap["Sleep"] = (new SleepCommand());
    commandMap["while"] = (new whileCommand());

    int index = this->index;
    //commandOfSimulatorMap.put()
    while (index != stringVector.size()) {
        string currentString = stringVector.at(index);
        //dealing with command
        //Check if its a command that exists in commandMap
        if (commandMap.find(currentString) != commandMap.end()) {
            //todo pass a pointer of the map to update them
            cout << currentString << endl;
            try {
                index = commandMap[currentString]->execute(stringVector, symbolTable, index, scope);
            }
            catch (const char *e) {
                cout << e << endl;
            }
//            while (!symbolTable->isConnected) {
//                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//            }
        } else { //   dealing with update var val;
            index = (new SetCommand())->execute(stringVector, symbolTable, index, this->scope);
            cout << currentString << endl;
        }
    }
}

Parser::Parser(vector<string> stringVector1,
               SymbolTable *symbolTable1, int index, int scope) {
    this->symbolTable = symbolTable1;
    this->stringVector = stringVector1;
    this->index = index;
    this->scope = scope;
}

