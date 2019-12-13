#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include "Command.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

vector<string> lexer(string fileName);

void parser(vector<string> vector);

class Var {
    string varName;
    double value;
    string updateBy;
    string sim;
    string scope;
public:
    Var(string name, double val, string update, string sim1, string scope) {
        this->value = val;
        this->sim = sim;
        this->varName = name;
        this->updateBy = update;
        this->scope = scope;
    }
};

#define PORT 5400
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
    //parser(stringVectorFromFile);
    return 0;
}

/*void parser(vector<string> StringVector) {
    map <string, Var> mapVar;
    map <string, Command> commandMap;
    //vector<string> =
    //vector<string>::iterator ptr =.begin();
    //for(ptr = ve)

    //for ()

}*/

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




