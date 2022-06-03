#include <string>

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace Constants
{
    const std::string ASSERT_TEST = "test/assert_test.cpp";
    const std::string TEST_FOLDER = "test/";
    const std::string RUNNABLE = "runnable-";
    const std::string CPP = ".cpp";

    const std::string CXX = "g++ -std=c++17 -fpermissive ";
    const std::string OBJECT_FLAG = " -o ";
    const std::string FIND_OBJECTS = " $(find src -type f -name \"*.o\") ";

    const std::string RESET = "\033[0m";
    const std::string BOLDRED = "\033[1m\033[31m";
    const std::string BOLDGREEN = "\033[1m\033[32m";
    const std::string BOLDCYAN = "\033[1m\033[36m";
    const std::string BOLDWHITE = "\033[1m\033[37m";

    const std::string RUN_TESTS_FILE = "runners/run_tests.cpp";
    const std::string TEST_SUITE_BOILERPLATE = "boilerplates/test_suite_base.cpp";
}

#endif
