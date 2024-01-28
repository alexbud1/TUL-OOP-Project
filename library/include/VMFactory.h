//
// Created by Oleksii Budzinskyi on 28/01/2024.
//

#ifndef CRANEPROJECT_VMFACTORY_H
#define CRANEPROJECT_VMFACTORY_H
#include "VirtualMachine.h"
#include <memory>

class VMFactory {
public:
    virtual std::unique_ptr<VirtualMachine> CreateVM(
            unsigned int id,
            string name,
            string cpuModel,
            unsigned int numberOfCores,
            string gpuModel,
            unsigned int ramSize,
            unsigned int diskSize,
            int powerConsumption
            ) const = 0;
    virtual ~VMFactory() = default;
};

#endif //CRANEPROJECT_VMFACTORY_H
