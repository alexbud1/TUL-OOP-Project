//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_STANDARDVM_H
#define CRANEPROJECT_STANDARDVM_H
#include "VirtualMachine.h"
#include <string>

using namespace std;

class StandardVM : public VirtualMachine {
public:
    void displayInfo() const override;
};

#endif //CRANEPROJECT_STANDARDVM_H
