//
// Created by Oleksii Budzinskyi on 29/01/2024.
//
#include <boost/test/unit_test.hpp>
#include "PerformanceVM.h"
#include "PerformanceVMFactory.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(PerformanceVMTestSuite)

        BOOST_AUTO_TEST_CASE(testPerformanceVM_activatePerformanceMode) {
            PerformanceVMFactory performanceVMFactory;
            auto performanceVM = performanceVMFactory.CreateVM(1, "PerformanceVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "PerformanceVM");
            // Check if it's an PerformanceVM and call the specific method
            if (auto* performanceVMConcrete = dynamic_cast<PerformanceVM*>(performanceVM.get())) {
                performanceVMConcrete->activatePerformanceMode();
                BOOST_CHECK_EQUAL(performanceVMConcrete->getIsPerformance(), true);
            }
        }
        BOOST_AUTO_TEST_CASE(testPerformanceVM_deactivatePerformanceMode) {
            PerformanceVMFactory performanceVMFactory;
            auto performanceVM = performanceVMFactory.CreateVM(1, "PerformanceVM", "Intel Core i5", 4, "NVIDIA GeForce GTX 1050", 8, 256, 500, "PerformanceVM");
            // Check if it's an PerformanceVM and call the specific method
            if (auto* performanceVMConcrete = dynamic_cast<PerformanceVM*>(performanceVM.get())) {
                BOOST_CHECK_EQUAL(performanceVMConcrete->getIsPerformance(), false);
            }
        }
BOOST_AUTO_TEST_SUITE_END()
