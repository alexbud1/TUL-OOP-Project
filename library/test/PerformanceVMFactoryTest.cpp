//
// Created by Oleksii Budzinskyi on 29/01/2024.
//
#include <boost/test/unit_test.hpp>
#include "PerformanceVMFactory.h"

BOOST_AUTO_TEST_SUITE(PerformanceVMFactoryTestSuite)

    BOOST_AUTO_TEST_CASE(testPerformanceVMFactory_createVM) {
        PerformanceVMFactory performanceVMFactory;
        auto performanceVM = performanceVMFactory.CreateVM(1, "PerformanceVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "PerformanceVM");
        BOOST_CHECK(performanceVM != nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()