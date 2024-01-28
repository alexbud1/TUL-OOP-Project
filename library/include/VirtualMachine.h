//
// Created by Oleksii Budzinskyi on 27/01/2024.
//

#ifndef CRANEPROJECT_VIRTUALMACHINE_H
#define CRANEPROJECT_VIRTUALMACHINE_H

#include <string>

using namespace std;

class VirtualMachine {
private:
    unsigned int id;
    std::string name;
    std::string cpuModel;
    unsigned int numberOfCores;
    std::string gpuModel;
    unsigned int ramSize;
    unsigned int diskSize;
    int powerConsumption; // in Watts

public:
    // Pure virtual function to make the class abstract
    virtual void displayInfo() const = 0;

    unsigned int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getCpuModel() const { return cpuModel; }
    unsigned int getNumberOfCores() const { return numberOfCores; }
    std::string getGpuModel() const { return gpuModel; }
    unsigned int getRamSize() const { return ramSize; }
    unsigned int getDiskSize() const { return diskSize; }
    int getPowerConsumption() const { return powerConsumption; }

    void setId(unsigned int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setCpuModel(const std::string& newCpuModel) { cpuModel = newCpuModel; }
    void setNumberOfCores(unsigned int newNumberOfCores) { numberOfCores = newNumberOfCores; }
    void setGpuModel(const std::string& newGpuModel) { gpuModel = newGpuModel; }
    void setRamSize(unsigned int newRamSize) { ramSize = newRamSize; }
    void setDiskSize(unsigned int newDiskSize) { diskSize = newDiskSize; }
    void setPowerConsumption(int newPowerConsumption) { powerConsumption = newPowerConsumption; }

    // Destructor (virtual to ensure proper cleanup in derived classes)
    virtual ~VirtualMachine() = default;
};

#endif //CRANEPROJECT_VIRTUALMACHINE_H
