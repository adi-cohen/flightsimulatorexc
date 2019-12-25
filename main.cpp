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
#include "Interpreter.h"

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
    Parser* mainParser = new Parser(stringVectorFromFile,  mainSymbolTable, 0, mainScope);
    mainParser->RunParser();

    /* for debug
    Interpreter* i8 = new Interpreter();
    Interpreter* i9 = new Interpreter();
    Interpreter* i10 = new Interpreter();
    Expression* e11 = nullptr;
    Expression* el2 = nullptr;
    Expression* el3 = nullptr;
    try {
        //i8->setVariables("roll=100;heading=50");
        //i9->setVariables("roll=100;heading=50");
        i10->setVariables("h0=100;heading=100");
        //e11 = i8->interpret("-roll/70"); // works good!
        //el2 = i9->interpret("-roll / 70"); // doesn't work because of the space! - Line 276 in class Interpreter!
        el3 = i10->interpret("h0-heading/80"); // works good without spaces!
        //std::cout << "el1 result: " << e11->calculate() << std::endl;
        //std::cout << "el2 result: " << el2->calculate() << std::endl;
        std::cout << "el3 result: " << el3->calculate() << std::endl;
        delete e11;
        delete i8;
        delete el2;
        delete i9;
    } catch (const char* e) {
        if (e11 != nullptr) {
            delete e11;
        }
        if (i8 != nullptr) {
            delete i8;
        }
        std::cout << e << std::endl;
    }*/
    return 0;
}



#pragma clang diagnostic pop