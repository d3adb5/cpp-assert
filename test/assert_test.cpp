#include <iostream>
#include "../include/core/assert.hpp"

void run()
{
    std::cout << assert::get_test_name();
    assert::assert_equals(0, assert::get_assertions());
    assert::assert_equals(0, assert::get_test_count());
    assert::assert_equals(0, assert::get_failures());
    assert::assert_equals("", assert::get_test_name());

    assert::testing("A very simple test");
    assert::assert_equals(1, 1);
    assert::assert_equals(1, 3);

    assert::testing("Another very simple test");
    assert::assert_equals(1, 2);
    assert::assert_equals(2, 2);
    assert::assert_equals(4, 2);

    assert::testing("Testing the equality of strings");
    assert::assert_equals("foo", "foo");
    assert::assert_equals("foo", "bar");
    assert::assert_equals("bar", "bar");

    assert::testing("Testing the equality of booleans");
    assert::assert_equals(false, false);
    assert::assert_equals(true, true);
    assert::assert_equals(false, true);

    assert::testing("Testing the equality of double");
    assert::assert_equals(2.0, 2.0);
    assert::assert_equals(1.0, 2.0);
    assert::assert_equals(3.0, 3.00);

    assert::testing("Testing the membership in [1, 2, 3]");

    std::vector<int> numbers = {1, 2, 3};
    assert::assert_contains(numbers, 1);
    assert::assert_contains(numbers, 2);
    assert::assert_contains(numbers, 3);
    assert::assert_contains(numbers, 0);
}
