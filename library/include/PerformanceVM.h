//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_PERFORMANCEVM_H
#define CRANEPROJECT_PERFORMANCEVM_H
#include "VirtualMachine.h"
#include <string>

using namespace std;

class PerformanceVM : public VirtualMachine {
private:
    bool isPerformance;
public:
    void displayInfo() const override;
    void activatePerformanceMode();
    void deactivatePerformanceMode();
};
#endif //CRANEPROJECT_PERFORMANCEVM_H
