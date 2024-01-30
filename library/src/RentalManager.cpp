//
// Created by Oleksii Budzinskyi on 28/01/2024.
//
#include "RentalManager.h"
#include "JSONUtility.h"
#include<cstdlib>
#include <algorithm>
#include "CLIInterface.h"
#include <iostream>
using namespace std;

RentalManager::RentalManager() = default;

RentalManager::~RentalManager() = default;

bool RentalManager::rentVM(string& login, string& vm_type) {
    try {

        if (RentalManager::checkVMAvailability(vm_type)) {
            json jsonData = JSONUtility::readJSONFromFile("../../available_vms.json");

            // Check if the "virtual_machines" array exists in the JSON
            if (jsonData.find("virtual_machines") != jsonData.end() && jsonData["virtual_machines"].is_array()) {
                // Iterate through each VM in the "virtual_machines" array
                for (auto &available_vm_type: jsonData["virtual_machines"]) {
                    // Check if the "type" field exists for the current VM
                    if (available_vm_type.find("type") != available_vm_type.end() &&
                        available_vm_type["type"].is_string()) {
                        // Compare the vm_type with the provided vm_type
                        if (available_vm_type["type"] == vm_type) {
                            // Check if the "amount" field exists
                            if (available_vm_type.find("amount") != available_vm_type.end() &&
                                available_vm_type["amount"].is_number()) {
                                // Update the amount in the JSON data
                                available_vm_type["amount"] = available_vm_type["amount"].get<int>() - 1;

                                // Save the modified JSON data back to the file
                                JSONUtility::writeJSONToFile("../../available_vms.json", jsonData);
                            }
                        }
                    }
                }
            }

            json rentedVMsData = JSONUtility::readJSONFromFile("../../rented_vms.json");

            // Check if the "virtual_machines" array exists in the JSON
            if (rentedVMsData.find("virtual_machines") != rentedVMsData.end() &&
                rentedVMsData["virtual_machines"].is_array()) {
                srand((unsigned) time(NULL));
                rentedVMsData["virtual_machines"].push_back({
                                                                    {"id",      rand() % 10000},
                                                                    {"login",   login},
                                                                    {"vm_type", vm_type}
                                                            });
                JSONUtility::writeJSONToFile("../../rented_vms.json", rentedVMsData);
                return true;
            }else{
                throw std::runtime_error("Error: rented_vms.json file is corrupted");
            }
        }
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return false;
}

bool RentalManager::checkVMAvailability(string& vm_type) {
    try{
        json jsonData = JSONUtility::readJSONFromFile("../../available_vms.json");

        // Check if the "available_vms" array exists in the JSON
        if (jsonData.find("virtual_machines") != jsonData.end() && jsonData["virtual_machines"].is_array()) {
            // Iterate through each VM in the "available_vms" array
            for (const auto& available_vm_type : jsonData["virtual_machines"]) {
                // Check if the "vm_type" field exists for the current VM
                if (available_vm_type.find("type") != available_vm_type.end() && available_vm_type["type"].is_string()) {
                    // Compare the vm_type with the provided vm_type
                    if (available_vm_type["type"] == vm_type) {
                        if (available_vm_type["amount"] > 0){
                            return true;
                        }
                    }
                }
            }
        }else{
            throw std::runtime_error("Error: available_vms.json file is corrupted");
        }
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    json jsonData = JSONUtility::readJSONFromFile("../../available_vms.json");

    // Check if the "available_vms" array exists in the JSON
    if (jsonData.find("virtual_machines") != jsonData.end() && jsonData["virtual_machines"].is_array()) {
        // Iterate through each VM in the "available_vms" array
        for (const auto& available_vm_type : jsonData["virtual_machines"]) {
            // Check if the "vm_type" field exists for the current VM
            if (available_vm_type.find("type") != available_vm_type.end() && available_vm_type["type"].is_string()) {
                // Compare the vm_type with the provided vm_type
                if (available_vm_type["type"] == vm_type) {
                    if (available_vm_type["amount"] > 0){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool RentalManager::returnVM(string& login, string& vm_type, unsigned int id) {
    json rentedVMsData = JSONUtility::readJSONFromFile("../../rented_vms.json");

    // Check if the "virtual_machines" array exists in the JSON
    if (rentedVMsData.find("virtual_machines") != rentedVMsData.end() && rentedVMsData["virtual_machines"].is_array()) {
        auto& virtualMachinesArray = rentedVMsData["virtual_machines"];
        // Find the element to delete based on login, vm_type, and id
        auto it = std::find_if(virtualMachinesArray.begin(), virtualMachinesArray.end(),
                               [&](const json& vm) {
                                   return vm.is_object() &&
                                          vm.value("login", "") == login &&
                                          vm.value("vm_type", "") == vm_type &&
                                          vm.value("id", 0) == id; // Get "id" as a number
                               });

        // Check if the element was found
        if (it != virtualMachinesArray.end()) {
            // Erase the found element from the "virtual_machines" array
            virtualMachinesArray.erase(it);

            // Save the modified JSON data back to the file
            JSONUtility::writeJSONToFile("../../rented_vms.json", rentedVMsData);
        }
    }

    json availableVMsData = JSONUtility::readJSONFromFile("../../available_vms.json");

    // Check if the "virtual_machines" array exists in the JSON
    if (availableVMsData.find("virtual_machines") != availableVMsData.end() && availableVMsData["virtual_machines"].is_array()) {
        // Iterate through each VM in the "virtual_machines" array
        for (auto& available_vm_type : availableVMsData["virtual_machines"]) {
            // Check if the "type" field exists for the current VM
            if (available_vm_type.find("type") != available_vm_type.end() && available_vm_type["type"].is_string()) {
                // Compare the vm_type with the provided vm_type
                if (available_vm_type["type"] == vm_type) {
                    // Check if the "amount" field exists
                    if (available_vm_type.find("amount") != available_vm_type.end() && available_vm_type["amount"].is_number()) {
                        // Update the amount in the JSON data
                        available_vm_type["amount"] = available_vm_type["amount"].get<int>() + 1;

                        // Save the modified JSON data back to the file
                        JSONUtility::writeJSONToFile("../../available_vms.json", availableVMsData);
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool RentalManager::getVMsRentedByCustomer(string& login) {
    json rentedVMsData = JSONUtility::readJSONFromFile("../../rented_vms.json");

    // Check if the "virtual_machines" array exists in the JSON
    if (rentedVMsData.find("virtual_machines") != rentedVMsData.end() && rentedVMsData["virtual_machines"].is_array()) {
        // Iterate through each VM in the "virtual_machines" array
        for (const auto& rented_vm : rentedVMsData["virtual_machines"]) {
            // Check if the "login" field exists for the current VM
            if (rented_vm.find("login") != rented_vm.end() && rented_vm["login"].is_string()) {
                // Compare the login with the provided login
                if (rented_vm["login"] == login) {
                    if (rented_vm.find("vm_type") != rented_vm.end() && rented_vm["vm_type"].is_string()) {
                        cout << "VM ID: " << rented_vm["id"] << " " << rented_vm["vm_type"] << endl;
                    }
//                    cout << "VM ID: " << rented_vm["id"] << " " << rented_vm["vm_type"] << endl;
                }
            }
        }
        return true;
    }

    return false; // CustomerManager not found
}

string RentalManager::getVMType(string& login, unsigned int vm_id) {
    json rentedVMsData = JSONUtility::readJSONFromFile("../../rented_vms.json");

    // Check if the "virtual_machines" array exists in the JSON
    if (rentedVMsData.find("virtual_machines") != rentedVMsData.end() && rentedVMsData["virtual_machines"].is_array()) {
        // Iterate through each VM in the "virtual_machines" array
        for (const auto& rented_vm : rentedVMsData["virtual_machines"]) {
            // Check if the "login" field exists for the current VM
            if (rented_vm.find("login") != rented_vm.end() && rented_vm["login"].is_string()) {
                // Compare the login with the provided login
                if (rented_vm["login"] == login) {
                    if (rented_vm.find("vm_type") != rented_vm.end() && rented_vm["vm_type"].is_string()) {
                        if (rented_vm.find("id") != rented_vm.end() && rented_vm["id"].is_number()) {
                            if (rented_vm["id"] == vm_id) {
                                return rented_vm["vm_type"];
                            }
                        }
                    }
                }
            }
        }
    }

    return ""; // CustomerManager not found
}
