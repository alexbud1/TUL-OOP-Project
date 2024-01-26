#include <iostream>
#include "CLIInterface.h"
#include "utils.cpp"
#include <vector>
#include <string>
#include "AuthManager.h"

using namespace std;

int main() {
    string welcome_message = "\nWelcome to the Virtual Machine Renting System!\n\nFor the further interaction you need to login or register. Please make your choice by entering desired number and press Enter.\n\n1. Login\n2. Register\n3. Exit\n";
    CLIInterface::displayMessage(welcome_message);

    while (true){
        string choice = CLIInterface::getInput();
        vector<string> options = {"1", "2", "3"};

        if (!check_option_validity(choice, options)){
            continue;
        }

        if (choice == "1") {
            string login_message = "Please enter your login and press Enter.";
            CLIInterface::displayMessage(login_message);
            string login = CLIInterface::getInput();
            string password_message = "Please enter your password and press Enter.";
            CLIInterface::displayMessage(password_message);
            string password = CLIInterface::getInput();
            bool user_exists = AuthManager::authenticateUser(login, password);
            if (!user_exists){
                string error_message = "Authentication failed. Please try again.";
                CLIInterface::displayMessage(error_message);
                continue;
            }
            string success_message = "You have successfully logged in!";
            CLIInterface::displayMessage(success_message);
            break;
        }else if (choice == "2"){
            string login_message = "Please enter your login and press Enter.";
            CLIInterface::displayMessage(login_message);
            string login = CLIInterface::getInput();
            string password_message = "Please enter your password and press Enter.";
            CLIInterface::displayMessage(password_message);
            string password = CLIInterface::getInput();
            string success_message = "You have successfully registered!";
            CLIInterface::displayMessage(success_message);
            break;
        }else if (choice == "3"){
            string exit_message = "Thank you for using our system. Goodbye!";
            CLIInterface::displayMessage(exit_message);
            break;
        }

        break;
    }
    return 0;
}