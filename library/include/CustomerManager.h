//
// Created by Oleksii Budzinskyi on 27/01/2024.
//

#ifndef CRANEPROJECT_CUSTOMERMANAGER_H
#define CRANEPROJECT_CUSTOMERMANAGER_H
#include <string>

using namespace std;

class CustomerManager {
public:
    CustomerManager();
    virtual ~CustomerManager();

    static string getCurrentCustomerName(string& login);
    static string getCurrentCustomerSurname(string& login);
    static string getCurrentCustomerEmail(string& login);

    static string setCurrentCustomerName(string& login, string& name);
    static string setCurrentCustomerSurname(string& login, string& surname);
    static string setCurrentCustomerEmail(string& login, string& email);

};


#endif //CRANEPROJECT_CUSTOMERMANAGER_H
