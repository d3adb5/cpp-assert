#include "../../include/core/assert.hpp"

namespace assert
{
    namespace
    {
        std::string suite_name = "";
        long assertions = 0;
        long test_count = 0;
        long failures = 0;
    }

    std::string get_test_name()
    {
        return suite_name;
    }

    long get_assertions()
    {
        return assertions;
    }

    long get_test_count()
    {
        return test_count;
    }

    long get_failures()
    {
        return failures;
    }

    void set_assertions(long new_value) { assertions = new_value; }
    void set_test_count(long new_value) { test_count = new_value; }
    void set_failures(long new_value) { failures = new_value; }

    void show_statistics()
    {
        std::cout << Constants::BOLDWHITE;
        std::cout << "Ran "
                  << test_count
                  << " tests and "
                  << assertions
                  << " assertions."
                  << std::endl;
        std::cout << failures << " failures." << std::endl;
        std::cout << Constants::RESET;
    }

    void testing(const std::string test_name)
    {
        std::cout << Constants::BOLDGREEN << std::endl;
        std::cout << "TESTING ";
        std::cout << "\"" << test_name << "\"\n"
                  << std::endl;

        suite_name = test_name;
        test_count++;
    }
}
