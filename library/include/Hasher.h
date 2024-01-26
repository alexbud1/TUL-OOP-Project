//
// Created by Oleksii Budzinskyi on 27/10/2023.
//

#ifndef CRANEPROJECT_HASHER_H
#define CRANEPROJECT_HASHER_H

#include <string>

using namespace std;

class Hasher {
public:
    Hasher();
    virtual ~Hasher();

    // hashing algorithm SHA-256 is used
    static string hashString(const string& password);
};

#endif //CRANEPROJECT_HASHER_H