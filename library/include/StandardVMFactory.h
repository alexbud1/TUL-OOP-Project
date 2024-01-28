//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_STANDARDVMFACTORY_H
#define CRANEPROJECT_STANDARDVMFACTORY_H
#include "VirtualMachine.h"
#include <memory>
#include "VMFactory.h"
#include "StandardVM.h"


using namespace std;

class StandardVMFactory : public VMFactory {
public:
    std::unique_ptr<VirtualMachine> CreateVM(
            unsigned int id,
            string name,
            string cpuModel,
            unsigned int numberOfCores,
            string gpuModel,
            unsigned int ramSize,
            unsigned int diskSize,
            int powerConsumption
    ) const override {
        std::unique_ptr<VirtualMachine> standardVM(new StandardVM());
        standardVM->setId(id);
        standardVM->setName(name);
        standardVM->setCpuModel(cpuModel);
        standardVM->setNumberOfCores(numberOfCores);
        standardVM->setGpuModel(gpuModel);
        standardVM->setRamSize(ramSize);
        standardVM->setDiskSize(diskSize);
        standardVM->setPowerConsumption(powerConsumption);

        return standardVM;
    }
};

#endif //CRANEPROJECT_STANDARDVMFACTORY_H
