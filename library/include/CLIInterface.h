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
    static void display_profile_info(string& login);
    static bool display_profile_menu(string& login);
    static bool go_to_main_menu(string& login);
    static bool check_option_validity(string option, const vector<string>& options);
};

#endif //CRANEPROJECT_CLIINTERFACE_H
