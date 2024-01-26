//
// Created by Oleksii Budzinskyi on 26/01/2024.
//

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "AuthManager.h"


BOOST_AUTO_TEST_SUITE(AuthManagerTestSuite)

    BOOST_AUTO_TEST_CASE(testAuthManager_authenticateUser) {
        AuthManager authManager;
        string username = "admin";
        string password = "test";
        BOOST_CHECK(authManager.authenticateUser(username, password));
    }

BOOST_AUTO_TEST_SUITE_END()