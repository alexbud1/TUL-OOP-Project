//
// Created by Oleksii Budzinskyi on 28/01/2024.
//
#include "CLIInterface.h"
#include <string>
#include "StandardVM.h"
using namespace std;

void StandardVM::displayInfo() const {
    std::string infoString = "'Standard Virtual Machine' Information:\n";
    infoString += "ID: " + std::to_string(getId()) + "\n";
    infoString += "Name: " + getName() + "\n";
    infoString += "CPU Model: " + getCpuModel() + "\n";
    infoString += "Number of Cores: " + std::to_string(getNumberOfCores()) + "\n";
    infoString += "GPU Model: " + getGpuModel() + "\n";
    infoString += "RAM Size: " + std::to_string(getRamSize()) + " GB\n";
    infoString += "Disk Size: " + std::to_string(getDiskSize()) + " GB\n";
    infoString += "Power Consumption: " + std::to_string(getPowerConsumption()) + " Watts\n";

    CLIInterface::displayMessage(infoString);
}
