#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"
#include "../test/assert_equals_test.cpp"
#include "../test/unit_test_factory_test.cpp"

UnitTest* UnitTestFactory::create(std::string const& type) {
    if (type == "assert_equals_test") {
        return new AssertEqualsTest();
    }

    if (type == "unit_test_factory_test") {
        return new UnitTestFactoryTest();
    }
    
    // TODO throw exception
    return nullptr;
}