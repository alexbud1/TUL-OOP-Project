//
// Created by Oleksii Budzinskyi on 26/01/2024.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test_log.hpp>
#include "CLIInterface.h"


BOOST_AUTO_TEST_SUITE(CLIInterfaceTestSuite)
    struct cout_redirect {
        explicit cout_redirect( std::streambuf * new_buffer )
                : old( std::cout.rdbuf( new_buffer ) )
        { }

        ~cout_redirect( ) {
            std::cout.rdbuf( old );
        }

    private:
        std::streambuf * old;
    };

    BOOST_AUTO_TEST_CASE(CLIInterfaceTestSuite_displayMessage) {
        boost::test_tools::output_test_stream output;
        cout_redirect guard( output.rdbuf( ) );

        string message = "Test";
        CLIInterface::displayMessage(message);

        BOOST_CHECK( output.is_equal( message ) );
    }

BOOST_AUTO_TEST_SUITE_END()