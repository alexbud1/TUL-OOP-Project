//
// Created by Oleksii Budzinskyi on 08/11/2023.
//

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <string>
#include "Hasher.h"


BOOST_AUTO_TEST_SUITE(HasherTestSuite)

    BOOST_AUTO_TEST_CASE(testContainerStack_emptyConstructor_sizeShouldBeZero) {
        string password = "password";
        string hashed_password = Hasher::hashString(password);
        BOOST_CHECK_EQUAL(hashed_password, "5e884898da2847151d0e56f8dc6292773603dd6aabbdd62a11ef721d1542d8");
    }

BOOST_AUTO_TEST_SUITE_END()