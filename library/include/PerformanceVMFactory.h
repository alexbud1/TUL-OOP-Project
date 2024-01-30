//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_PERFORMANCEVMFACTORY_H
#define CRANEPROJECT_PERFORMANCEVMFACTORY_H
#include "VirtualMachine.h"
#include <memory>
#include "VMFactory.h"
#include "PerformanceVM.h"

using namespace std;

class PerformanceVMFactory : public VMFactory {
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
            string vm_type
    ) const override {
        std::unique_ptr<VirtualMachine> performanceVM(new PerformanceVM());
        performanceVM->setId(id);
        performanceVM->setName(name);
        performanceVM->setCpuModel(cpuModel);
        performanceVM->setNumberOfCores(numberOfCores);
        performanceVM->setGpuModel(gpuModel);
        performanceVM->setRamSize(ramSize);
        performanceVM->setDiskSize(diskSize);
        performanceVM->setPowerConsumption(powerConsumption);
        performanceVM->setVMType("PerformanceVM");
        return performanceVM;
    }
};

#endif //CRANEPROJECT_PERFORMANCEVMFACTORY_H
