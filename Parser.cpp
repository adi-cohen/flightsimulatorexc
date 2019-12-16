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
#include "SymbolTable.h"

//void parser(vector<string> stringVector) {


//Parser::Parser(SymbolTable symTable, vector<string> stringVector1) {
//    this->symbolTable = symTable;
//    this->stringVector = stringVector1;
//
//}

void Parser::RunParser() {

    map<string, Var *>* varMap = symbolTable->ptrVarMap; //from name to var.
    map<string, Var *>* simMap = symbolTable->ptrSimMap; //from sim to var.
    map<string, Command *> commandMap;
    // insert command to map
    commandMap.insert(std::pair<string, Command *>("openDataServer", (new OpenDataServer())));
    commandMap["connectControlClient"] = (new ConnectClientCommand());
    commandMap["var"] = (new CreateVarCommand());
    commandMap["Print"] = (new printCommand());
    commandMap["Sleep"] = (new SleepCommand());


    int index = 0;
    //commandOfSimulatorMap.put()
    while (index != stringVector.size()) {
        string currentString = stringVector.at(index);
        //dealing with command
        //Check if its a command that exists in commandMap
        if (commandMap.find(currentString) != commandMap.end()) {
            //todo pass a pointer of the map to update them
            index = commandMap[currentString]->execute(stringVector, *varMap, *simMap, index);
        } else { //   dealing with update var val;
            (new SetCommend())->execute(stringVector, *varMap, *simMap, index);
        }
    }
}


Parser::Parser(vector<string> stringVector1, SymbolTable *symbolTable1) {
    this->symbolTable = symbolTable1;
    this->stringVector = stringVector1;

}



