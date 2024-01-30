//
// Created by Oleksii Budzinskyi on 28/01/2024.
//
#include <boost/test/unit_test.hpp>
#include "RentalManager.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(RentalManagerTestSuite)

    BOOST_AUTO_TEST_CASE(testRentalManager_checkVMAvailability) {
    std::string vm_type = "EcoVM";
    BOOST_CHECK(RentalManager::checkVMAvailability(vm_type));
    }

BOOST_AUTO_TEST_SUITE_END()