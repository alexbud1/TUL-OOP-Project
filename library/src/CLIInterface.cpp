//
// Created by Oleksii Budzinskyi on 16/01/2024.
//
#include "CLIInterface.h"
#include <iostream>
#include <string>
#include "CustomerManager.h"


using namespace std;

bool CLIInterface::check_option_validity(string option, const vector<string>& options){
    for (const auto& opt : options){
        if (opt == option){
            return true;
        }
    }
    string error_message = "Invalid option. Please try again.";
    CLIInterface::displayMessage(error_message);
    return false;
}

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

void CLIInterface::display_profile_info(string& login){
    string name = CustomerManager::getCurrentCustomerName(login);
    string surname = CustomerManager::getCurrentCustomerSurname(login);
    string email = CustomerManager::getCurrentCustomerEmail(login);

    string profile_message = "Your profile:\nName: " + name + "\nSurname: " + surname + "\nEmail: " + email;
    CLIInterface::displayMessage(profile_message);
}

bool CLIInterface::go_to_main_menu(string& login){
    string main_menu_msg = "Now you are in the main menu. Please make your choice by entering desired number and press Enter.\n\n1. Browse available plans\n2. Rent VM\n3. My profile\n4. Change profile\n5. Exit";
    CLIInterface::displayMessage(main_menu_msg);

    while(true){
        string choice = CLIInterface::getInput();
        vector<string> options = {"1", "2", "3", "4", "5"};

        if (!check_option_validity(choice, options)){
            continue;
        }

        if (choice == "1"){
            string plans_message = "Available plans:";
            CLIInterface::displayMessage(plans_message);
        }else if (choice == "2"){
            string rent_message = "Please enter the name of the plan you want to rent and press Enter.";
            CLIInterface::displayMessage(rent_message);
        }else if (choice == "3") {
            display_profile_info(login);
        }else if (choice == "4"){
            if(not display_profile_menu(login)){
                if(not go_to_main_menu(login)){
                    break;
                }
            }
        }else if (choice == "5"){
            string exit_message = "Thank you for using our system. Goodbye!";
            CLIInterface::displayMessage(exit_message);
            break;
        }
    }
    return false;
}

bool CLIInterface::display_profile_menu(string& login){
    string profile_message = "Please enter the number of the option you want to change and press Enter.\n\n1. Name\n2. Surname\n3. Email\n4. Back";
    CLIInterface::displayMessage(profile_message);

    while(true){
        string profile_choice = CLIInterface::getInput();
        vector<string> profile_options = {"1", "2", "3", "4"};

        if (!check_option_validity(profile_choice, profile_options)){
            continue;
        }

        if (profile_choice == "1"){
            string name_message = "Please enter your new name and press Enter.";
            CLIInterface::displayMessage(name_message);
            string name = CLIInterface::getInput();
            CustomerManager::setCurrentCustomerName(login, name);
            string success_message = "Your name has been successfully changed!";
            CLIInterface::displayMessage(success_message);
            break;
        }else if (profile_choice == "2"){
            string surname_message = "Please enter your new surname and press Enter.";
            CLIInterface::displayMessage(surname_message);
            string surname = CLIInterface::getInput();
            CustomerManager::setCurrentCustomerSurname(login, surname);
            string success_message = "Your surname has been successfully changed!";
            CLIInterface::displayMessage(success_message);
            break;

        }else if (profile_choice == "3"){
            string email_message = "Please enter your new email and press Enter.";
            CLIInterface::displayMessage(email_message);
            string email = CLIInterface::getInput();
            CustomerManager::setCurrentCustomerEmail(login, email);
            string success_message = "Your email has been successfully changed!";
            CLIInterface::displayMessage(success_message);
            break;

        }else if (profile_choice == "4"){
            break;
        }
    }
    return false;
}

