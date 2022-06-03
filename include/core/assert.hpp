#include <algorithm>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>
#include "../constants.hpp"

#ifndef ASSERT_HPP
#define ASSERT_HPP

/**
 * Header file with a namespace for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 2.0
 */

namespace assert
{
    void testing(const std::string);
    void show_statistics();

    std::string get_test_name();

    long get_assertions();
    long get_test_count();
    long get_failures();

    void set_assertions(long);
    void set_test_count(long);
    void set_failures(long);

    template <typename T, typename U>
    inline void assert_equals(T expected, U actual)
    {
        bool result = expected == actual;

        if (!result)
        {
            assertion_fail(get_test_name(), expected, actual);
            set_failures(get_failures() + 1);
        }

        set_assertions(get_assertions() + 1);
    }

    template <typename T>
    inline void assert_contains(std::vector<T> collection, T element)
    {
        auto begin = collection.begin();
        auto end = collection.end();
        bool result = std::find(begin, end, element) != end;

        if (!result)
        {
            membership_fail(get_test_name(), element);
            set_failures(get_failures() + 1);
        }

        set_assertions(get_assertions() + 1);
    }

    template <typename T, typename U>
    inline void assertion_fail(const std::string test, T expected, U received)
    {
        std::cout << Constants::BOLDRED;

        std::cout << "FAIL at " << test << ":" << std::endl;
        std::cout << "expected " << expected;
        std::cout << " but received " << received << std::endl;

        std::cout << Constants::RESET << std::endl;
    }

    template <typename T>
    inline void membership_fail(const std::string test, T expected)
    {
        std::cout << Constants::BOLDRED;

        std::cout << "FAIL at " << test << ":" << std::endl;

        std::cout << "the collection does not contain" << expected;
        std::cout << "." << std::endl;

        std::cout << Constants::RESET << std::endl;
    }
}

#endif
