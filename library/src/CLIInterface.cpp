//
// Created by Oleksii Budzinskyi on 16/01/2024.
//
#include "CLIInterface.h"
#include <iostream>
#include <string>
#include "CustomerManager.h"
#include "EcoVMFactory.h"
#include "StandardVMFactory.h"
#include "PerformanceVMFactory.h"
#include "RentalManager.h"

using namespace std;

bool CLIInterface::checkOptionValidity(string option, const vector<string>& options){
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

void CLIInterface::displayProfileInfo(string& login){
    string name = CustomerManager::getCurrentCustomerName(login);
    string surname = CustomerManager::getCurrentCustomerSurname(login);
    string email = CustomerManager::getCurrentCustomerEmail(login);

    string profile_message = "Your profile:\nName: " + name + "\nSurname: " + surname + "\nEmail: " + email;
    CLIInterface::displayMessage(profile_message);
}

bool CLIInterface::goToMainMenu(string& login){
    string main_menu_msg = "Now you are in the main menu. Please make your choice by entering desired number and press Enter.\n\n1. Browse available plans\n2. Rent VM\n3. My profile\n4. Change profile\n5. Manage VM's\n6. Exit";
    CLIInterface::displayMessage(main_menu_msg);

    while(true){
        string choice = CLIInterface::getInput();
        vector<string> options = {"1", "2", "3", "4", "5", "6"};

        if (!checkOptionValidity(choice, options)){
            continue;
        }

        if (choice == "1"){
            string plans_message = "Available plans:\n";
            CLIInterface::displayMessage(plans_message);

            EcoVMFactory ecoVMFactory;
            auto ecoVM = ecoVMFactory.CreateVM(1, "EcoVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "EcoVM");
            ecoVM->displayInfo();

            StandardVMFactory standardVMFactory;
            auto standardVM = standardVMFactory.CreateVM(2, "StandardVM", "Intel Core i7", 8, "NVIDIA GeForce GTX 1080", 16, 512, 1000, "StandardVM");
            standardVM->displayInfo();

            PerformanceVMFactory performanceVMFactory;
            auto performanceVM = performanceVMFactory.CreateVM(3, "PerformanceVM", "Intel Core i9", 16, "NVIDIA GeForce RTX 4090", 64, 4096, 2500, "PerformanceVM");
            performanceVM->displayInfo();

        }else if (choice == "2"){
            if(not displayRentVmMenu(login)) {
                if(not goToMainMenu(login)){
                    break;
                }
            }
        }else if (choice == "3") {
            displayProfileInfo(login);
        }else if (choice == "4"){
            if(not displayProfileMenu(login)){
                if(not goToMainMenu(login)){
                    break;
                }
            }
        }else if (choice == "5"){
            if(not displayManageVmsMenu(login)){
                if(not goToMainMenu(login)){
                    break;
                }
            }
        }else if (choice == "6"){
            string exit_message = "Thank you for using our system. Goodbye!";
            CLIInterface::displayMessage(exit_message);
            break;
        }
    }
    return false;
}

bool CLIInterface::displayProfileMenu(string& login){
    string profile_message = "Please enter the number of the option you want to change and press Enter.\n\n1. Name\n2. Surname\n3. Email\n4. Back";
    CLIInterface::displayMessage(profile_message);

    while(true){
        string profile_choice = CLIInterface::getInput();
        vector<string> profile_options = {"1", "2", "3", "4"};

        if (!checkOptionValidity(profile_choice, profile_options)){
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

bool CLIInterface::displayRentVmMenu(string& login){
    string rent_message = "Please enter the number of the plan you want to rent and press Enter.\n1. Eco Virtual machine\n2.Standard Virtual machine\n3. Performance Virtual machine\nIf you want to go back to the main menu, please enter 0.";
    CLIInterface::displayMessage(rent_message);

    while(true){
        string rent_choice = CLIInterface::getInput();
        vector<string> rent_options = {"0", "1", "2", "3"};

        if (!checkOptionValidity(rent_choice, rent_options)){
            continue;
        }

        if (rent_choice == "0"){
            if(not goToMainMenu(login)){
                break;
            }
        }else if (rent_choice == "1"){
            string vm_type = "EcoVM";
            if (RentalManager::rentVM(login, vm_type)) {
                 string success_message = "You have successfully rented EcoVM!";
                 CLIInterface::displayMessage(success_message);
            }else{
                string error_message = "Unfortunately, there are no available EcoVMs at the moment. Please try again later.";
                CLIInterface::displayMessage(error_message);
            }
            break;
        }else if (rent_choice == "2"){
            string vm_type = "StandardVM";
            if (RentalManager::rentVM(login, vm_type)) {
                string success_message = "You have successfully rented StandardVM!";
                CLIInterface::displayMessage(success_message);
            }else{
                string error_message = "Unfortunately, there are no available StandardVMs at the moment. Please try again later.";
                CLIInterface::displayMessage(error_message);
            }
            break;
        }else if (rent_choice == "3"){
            string vm_type = "PerformanceVM";
            if (RentalManager::rentVM(login, vm_type)) {
                string success_message = "You have successfully rented PerformanceVM!";
                CLIInterface::displayMessage(success_message);
            }else{
                string error_message = "Unfortunately, there are no available PerformanceVMs at the moment. Please try again later.";
                CLIInterface::displayMessage(error_message);
            }
            break;
        }
    }
    return false;
}

bool CLIInterface::displayManageVmsMenu(string &login) {
    string msg = "VM's rented by you:\n";
    CLIInterface::displayMessage(msg);
    RentalManager::getVMsRentedByCustomer(login);
    string vm_id_msg = "\nPlease enter the ID of the VM you want to return and press Enter. If you want to go back to the main menu, please enter 0.";
    CLIInterface::displayMessage(vm_id_msg);

    while(true) {
        string vm_id = CLIInterface::getInput();
        if (vm_id == "0") {
            break;
        } else {
            try{
                string vm_type = RentalManager::getVMType(login, stoi(vm_id));
                RentalManager::returnVM(login, vm_type, stoi(vm_id));
                string return_msg = "Your VM with ID: " + vm_id + " was returned.";
                CLIInterface::displayMessage(return_msg);
//                if (not goToMainMenu(login)) {
                    break;
//                }
            }catch (const std::invalid_argument& ia){
                string error_msg = "Invalid ID. Please try again.";
                CLIInterface::displayMessage(error_msg);
            }
        }
    }
    return false;
}