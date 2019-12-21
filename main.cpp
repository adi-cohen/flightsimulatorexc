#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-slicing"
#pragma ide diagnostic ignored "hicpp-use-auto"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Command.h"
#include "Var.h"
#include "Parser.h"
#include "lexer.h"
#include "DataReaderServer.h"

using namespace std;


void parser(vector<string> vector);

int main(int argc, char *argv[]) {
    vector<string> stringVectorFromFile;
    string fileName = argv[1];
    //insert the data from the file to the char vector
    try {
        lexer* l = new lexer(fileName);
        stringVectorFromFile = l->runLexer();
    } catch (const char *e) {
        cout << e << endl;
    }
    // from lexer to parser
    map<string, Var *> varMap; //from name to var.
    map<string, Var *> simMap; //from sim to var.
    map<string, Command *> commandMap;

    int mainScope = 0;
    SymbolTable* mainSymbolTable = new SymbolTable(varMap,simMap);
    DataReaderServer* mainDataReaderServer = new DataReaderServer();
    Parser* mainParser = new Parser(stringVectorFromFile, mainDataReaderServer, mainSymbolTable, 0, mainScope);
    mainParser->RunParser();
    double val;
    //mainDataReaderServer->printXML();
    bool exitFlag;
    int outSocket;
    return 0;
}



#pragma clang diagnostic pop