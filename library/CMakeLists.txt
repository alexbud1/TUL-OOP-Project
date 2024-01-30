cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        include/Hasher.h
        src/Hasher.cpp
        include/CLIInterface.h
        src/CLIInterface.cpp
        ../program/src/utils.cpp
        include/AuthManager.h
        src/AuthManager.cpp
        include/CustomerManager.h
        include/JSONUtility.h
        src/JSONUtility.cpp
        src/CustomerManager.cpp
        include/VirtualMachine.h
        include/EcoVM.h
        include/VMFactory.h
        include/EcoVMFactory.h
        src/EcoVM.cpp
        include/StandardVMFactory.h
        include/StandardVM.h
        src/StandardVM.cpp
        include/PerformanceVM.h
        src/PerformanceVM.cpp
        include/PerformanceVMFactory.h
        include/RentalManager.h
        src/RentalManager.cpp
)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
find_package(OpenSSL REQUIRED)
target_link_libraries(Library OpenSSL::SSL)
#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

set(SOURCE_TEST_FILES
        test/master.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES}
        test/HasherTest.cpp
        test/AuthManagerTest.cpp
        test/CLIInterfaceTest.cpp
        test/RentalManagerTest.cpp
        test/EcoVMTest.cpp
        test/EcoVMFactoryTest.cpp
        test/PerformanceVMTest.cpp
        test/PerformanceVMFactoryTest.cpp
        test/StandardVMFactoryTest.cpp
)

add_executable (TestContainer ${SOURCE_TEST_FILES})

target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

target_link_libraries (TestContainer
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(LibraryTest Test)

add_test(TestWeight TestContainer
        --report_level=detailed
        --log_level=all
        --color_output=yes
)