#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "IntRange.cpp"
#include "IntRange.hpp"

TEST_CASE( "Arguments initialized") {
    IntRange testing1;
    testing1.set_first(-10);
    testing1.set_second(45);

    REQUIRE( testing1.rangeСheck(0) == true);
    REQUIRE( testing1.rangeСheck(-10) == true);
    REQUIRE( testing1.rangeСheck(-15) == false);
    REQUIRE( testing1.rangeСheck(30) == true);
    REQUIRE( testing1.rangeСheck(45) == false);
    REQUIRE( testing1.rangeСheck(100) == false);
}
