//
// Created by Oleksii Budzinskyi on 29/01/2024.
//
#include <boost/test/unit_test.hpp>
#include "StandardVM.h"
#include "StandardVMFactory.h"

BOOST_AUTO_TEST_SUITE(StandardVMFactoryTestSuite)

    BOOST_AUTO_TEST_CASE(testStandardVMFactory_createVM) {
        StandardVMFactory standardVMFactory;
        auto standardVM = standardVMFactory.CreateVM(1, "StandardVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "StandardVM");
        BOOST_CHECK(standardVM != nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()