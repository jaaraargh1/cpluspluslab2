#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"



 
TEST_CASE ("Test Valid") {
    Time t = {23, 20,19};
    Time t2 = {22,11,44};

    CHECK(is_Valid(t));
       
}
