//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_RENTALMANAGER_H
#define CRANEPROJECT_RENTALMANAGER_H
#include <string>
#include "VirtualMachine.h"
#include <vector>

using namespace std;

class RentalManager {
public:
    RentalManager();
    virtual ~RentalManager();

    static bool rentVM(string& login, string& vm_type);
    static bool returnVM(string& login, string& vm_type, unsigned int vm_id);
    static bool checkVMAvailability(string& vm_type);
    static bool getVMsRentedByCustomer(string& login);
    static string getVMType(string& login, unsigned int vm_id);
};

#endif //CRANEPROJECT_RENTALMANAGER_H
