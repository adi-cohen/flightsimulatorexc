//
// Created by adi on 15/12/2019.
//

#include "Var.h"
#include "string"
#include "map"

using namespace std;


void Var::updateVal(double newVal, map<string, Var*> varMap, map<string, Var*> simMap) {
    this->value = newVal;
    if (updateSimulator) {
        //we need to update the var in the simMap to the new value

    }

}

Var::Var(string name, double val, bool update, string sim1, string scope) {
    this->value = val;
    this->sim = sim;
    this->varName = std::move(name);
    this->updateSimulator = update;
    this->scope = scope;
}
