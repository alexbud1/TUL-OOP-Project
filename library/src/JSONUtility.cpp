//
// Created by Oleksii Budzinskyi on 27/01/2024.
//
#include "JSONUtility.h"
#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

JSONUtility::JSONUtility() = default;

JSONUtility::~JSONUtility() = default;

json JSONUtility::readJSONFromFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    json jsonData;
    file >> jsonData;

    file.close();

    return jsonData;
}

void JSONUtility::writeJSONToFile(const std::string &filename, json &jsonData) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    file << jsonData.dump(4);

    file.close();
}