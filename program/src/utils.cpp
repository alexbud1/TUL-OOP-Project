//
// Created by Oleksii Budzinskyi on 16/01/2024.
//
#include <vector>
#include <string>
#include "CLIInterface.h"

using namespace std;

bool check_option_validity(string option, const vector<string>& options){
    for (const auto& opt : options){
        if (opt == option){
            return true;
        }
    }
    string error_message = "Invalid option. Please try again.";
    CLIInterface::displayMessage(error_message);
    return false;
}