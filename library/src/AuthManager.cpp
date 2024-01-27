//
// Created by Oleksii Budzinskyi on 16/01/2024.
//
#include "AuthManager.h"
#include "CLIInterface.h"
#include "Hasher.h"
#include "JSONUtility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

AuthManager::AuthManager() = default;

AuthManager::~AuthManager() = default;

bool isUserExist(const std::string& filename, const std::string& login) {
    json jsonData = JSONUtility::readJSONFromFile(filename);

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (const auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    return true; // CustomerManager found
                }
            }
        }
    }

    return false; // CustomerManager not found
}

bool isPasswordValid(const string& login, const string& password){
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (const auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "password" field exists for the current user
                    if (user.find("password") != user.end() && user["password"].is_string()) {
                        // Compare the password with the provided password
                        if (user["password"] == Hasher::hashString(password)) {
                            return true; // Password is valid
                        }
                    }
                }
            }
        }
    }

    return false; // Password is invalid
}

bool AuthManager::authenticateUser(const string& username, const string& password){
    if (isUserExist("../../users.json", username) && isPasswordValid(username, password)){
        return true;
    }
    return false;
}

bool AuthManager::registerUser(const string& username, const string& password){
    if (isUserExist("../../users.json", username)){
        string error = "CustomerManager with this login already exists. Please try again.";
        CLIInterface::displayMessage(error);
        return false;
    }

    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Add the new user to the "users" array
        jsonData["users"].push_back({
            {"login", username},
            {"password", Hasher::hashString(password)}
        });
    }

    std::ofstream fileOut("../../users.json");

    if (!fileOut.is_open()) {
        std::cout << "Error opening file: " << "../../users.json" << std::endl;
        return false;
    }

    fileOut << jsonData.dump(4) << std::endl;

    fileOut.close();

    return true;
}