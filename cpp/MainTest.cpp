//
// Created by Asha Agrawal on 3/5/2018.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

TEST_CASE("testNullInput", )
{

    REQUIRE(checkValidity(NULL) ==  "INVALID INPUT");
}





