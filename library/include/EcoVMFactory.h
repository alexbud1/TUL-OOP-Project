//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_ECOVMFACTORY_H
#define CRANEPROJECT_ECOVMFACTORY_H
#include "VirtualMachine.h"
#include <memory>
#include "VMFactory.h"
#include "EcoVM.h"

using namespace std;

class EcoVMFactory : public VMFactory {
public:
    std::unique_ptr<VirtualMachine> CreateVM(
            unsigned int id,
            string name,
            string cpuModel,
            unsigned int numberOfCores,
            string gpuModel,
            unsigned int ramSize,
            unsigned int diskSize,
            int powerConsumption,
            string s
            ) const override {
                std::unique_ptr<EcoVM> ecoVM(new EcoVM());
                ecoVM->setId(id);
                ecoVM->setName(name);
                ecoVM->setCpuModel(cpuModel);
                ecoVM->setNumberOfCores(numberOfCores);
                ecoVM->setGpuModel(gpuModel);
                ecoVM->setRamSize(ramSize);
                ecoVM->setDiskSize(diskSize);
                ecoVM->setPowerConsumption(powerConsumption);
                ecoVM->setVMType("EcoVM");
                 return ecoVM;
            }
};

#endif //CRANEPROJECT_ECOVMFACTORY_H
