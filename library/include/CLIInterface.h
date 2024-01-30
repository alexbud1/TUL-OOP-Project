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
    static void displayProfileInfo(string& login);
    static bool displayProfileMenu(string& login);
    static bool goToMainMenu(string& login);
    static bool checkOptionValidity(string option, const vector<string>& options);
    static bool displayRentVmMenu(string& login);
    static bool displayManageVmsMenu(string &login);
};

#endif //CRANEPROJECT_CLIINTERFACE_H
