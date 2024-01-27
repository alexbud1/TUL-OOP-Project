//
// Created by Oleksii Budzinskyi on 27/01/2024.
//

#ifndef CRANEPROJECT_JSONUTILITY_H
#define CRANEPROJECT_JSONUTILITY_H
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

class JSONUtility {
public:
    JSONUtility();
    virtual ~JSONUtility();

    static json readJSONFromFile(const string& filename);
    static void writeJSONToFile(const string& filename, json& jsonData);
};
#endif //CRANEPROJECT_JSONUTILITY_H
