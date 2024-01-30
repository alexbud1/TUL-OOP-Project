//
// Created by Oleksii Budzinskyi on 29/01/2024.
//
#include <boost/test/unit_test.hpp>
#include "EcoVM.h"
#include "EcoVMFactory.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(EcoVMTestSuite)

    BOOST_AUTO_TEST_CASE(testEcoVM_activateEcoMode) {
        EcoVMFactory ecoVMFactory;
        auto ecoVM = ecoVMFactory.CreateVM(1, "EcoVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "EcoVM");
        // Check if it's an EcoVM and call the specific method
        if (auto* ecoVMConcrete = dynamic_cast<EcoVM*>(ecoVM.get())) {
            ecoVMConcrete->activateEcoMode();
            BOOST_CHECK_EQUAL(ecoVMConcrete->getIsEco(), true);
        }
    }
    BOOST_AUTO_TEST_CASE(testEcoVM_deactivateEcoMode) {
        EcoVMFactory ecoVMFactory;
        auto ecoVM = ecoVMFactory.CreateVM(1, "EcoVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "EcoVM");
        // Check if it's an EcoVM and call the specific method
        if (auto* ecoVMConcrete = dynamic_cast<EcoVM*>(ecoVM.get())) {
            BOOST_CHECK_EQUAL(ecoVMConcrete->getIsEco(), false);
        }
    }
BOOST_AUTO_TEST_SUITE_END()