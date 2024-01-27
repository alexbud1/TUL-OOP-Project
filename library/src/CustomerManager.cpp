//
// Created by Oleksii Budzinskyi on 27/01/2024.
//
#include "CustomerManager.h"
#include "JSONUtility.h"
#include <iostream>
#include <string>

using namespace std;

CustomerManager::CustomerManager() = default;

CustomerManager::~CustomerManager() = default;

string CustomerManager::getCurrentCustomerName(string& login) {
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (const auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "name" field exists for the current user
                    if (user.find("name") != user.end() && user["name"].is_string()) {
                        return user["name"]; // Return the name
                    }
                }
            }
        }
    }

    return ""; // Return an empty string if the name was not found
}

string CustomerManager::getCurrentCustomerSurname(string& login) {
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (const auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "surname" field exists for the current user
                    if (user.find("surname") != user.end() && user["surname"].is_string()) {
                        return user["surname"]; // Return the surname
                    }
                }
            }
        }
    }

    return ""; // Return an empty string if the surname was not found
}

string CustomerManager::getCurrentCustomerEmail(string& login) {
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (const auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "email" field exists for the current user
                    if (user.find("email") != user.end() && user["email"].is_string()) {
                        return user["email"]; // Return the email
                    }
                }
            }
        }
    }

    return ""; // Return an empty string if the email was not found
}

string CustomerManager::setCurrentCustomerName(string& login, string& name) {
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "name" field exists for the current user
                    if (user.find("name") != user.end() && user["name"].is_string()) {
                        user["name"] = name; // Set the name
                        JSONUtility::writeJSONToFile("../../users.json", jsonData); // Write the changes to the file
                        return "Name was successfully changed."; // Return a success message
                    }
                }
            }
        }
    }

    return "Name was not changed."; // Return a failure message
}

string CustomerManager::setCurrentCustomerSurname(string& login, string& surname) {
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "surname" field exists for the current user
                    if (user.find("surname") != user.end() && user["surname"].is_string()) {
                        user["surname"] = surname; // Set the surname
                        JSONUtility::writeJSONToFile("../../users.json", jsonData); // Write the changes to the file
                        return "Surname was successfully changed."; // Return a success message
                    }
                }
            }
        }
    }

    return "Surname was not changed."; // Return a failure message
}

string CustomerManager::setCurrentCustomerEmail(string& login, string& email) {
    json jsonData = JSONUtility::readJSONFromFile("../../users.json");

    // Check if the "users" array exists in the JSON
    if (jsonData.find("users") != jsonData.end() && jsonData["users"].is_array()) {
        // Iterate through each user in the "users" array
        for (auto& user : jsonData["users"]) {
            // Check if the "login" field exists for the current user
            if (user.find("login") != user.end() && user["login"].is_string()) {
                // Compare the login with the provided login
                if (user["login"] == login) {
                    // Check if the "email" field exists for the current user
                    if (user.find("email") != user.end() && user["email"].is_string()) {
                        user["email"] = email; // Set the email
                        JSONUtility::writeJSONToFile("../../users.json", jsonData); // Write the changes to the file
                        return "Email was successfully changed."; // Return a success message
                    }
                }
            }
        }
    }

    return "Email was not changed."; // Return a failure message
}