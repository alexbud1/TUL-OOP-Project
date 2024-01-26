//
// Created by Oleksii Budzinskyi on 16/01/2024.
//

#ifndef CRANEPROJECT_AUTHMANAGER_H
#define CRANEPROJECT_AUTHMANAGER_H

#include <string>
using namespace std;

class AuthManager {
public:
    AuthManager();
    virtual ~AuthManager();

    static bool authenticateUser(const string& username, const string& password);
};

#endif //CRANEPROJECT_AUTHMANAGER_H
