//
// Created by Oleksii Budzinskyi on 16/01/2024.
//
#include "CLIInterface.h"
#include <iostream>
using namespace std;

CLIInterface::CLIInterface() = default;

CLIInterface::~CLIInterface() = default;

void CLIInterface::displayMessage(string& message){
    cout << message << endl;
}

string CLIInterface::getInput() {
    string input;
    getline(cin, input);
    return input;
}

