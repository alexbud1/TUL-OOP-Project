//
// Created by Oleksii Budzinskyi on 16/01/2024.
//

#ifndef CRANEPROJECT_CLIINTERFACE_H
#define CRANEPROJECT_CLIINTERFACE_H

#include <string>

using namespace std;

class CLIInterface {
public:
    CLIInterface();
    virtual ~CLIInterface();

    static void displayMessage(string& message);
    static string getInput();
};

#endif //CRANEPROJECT_CLIINTERFACE_H
