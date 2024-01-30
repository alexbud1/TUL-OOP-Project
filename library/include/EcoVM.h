//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_ECOVM_H
#define CRANEPROJECT_ECOVM_H

#include "VirtualMachine.h"
#include <string>

using namespace std;

class EcoVM : public VirtualMachine {
private:
    bool isEco;
public:
    void displayInfo() const override;
    void activateEcoMode();
    void deactivateEcoMode();
    bool getIsEco() const;
};

#endif //CRANEPROJECT_ECOVM_H
