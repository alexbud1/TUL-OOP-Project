//
// Created by Oleksii Budzinskyi on 29/01/2024.
//
#include <boost/test/unit_test.hpp>
#include "EcoVMFactory.h"

BOOST_AUTO_TEST_SUITE(EcoVMFactoryTestSuite)

    BOOST_AUTO_TEST_CASE(testEcoVMFactory_createVM) {
        EcoVMFactory ecoVMFactory;
        auto ecoVM = ecoVMFactory.CreateVM(1, "EcoVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "EcoVM");
        BOOST_CHECK(ecoVM != nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()