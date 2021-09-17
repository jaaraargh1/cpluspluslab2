#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"
using namespace std;


 
TEST_CASE("Test Valid") {
  Time t{23, 20,19, "am"};
  Time t2{22,11,44, "am"};

    CHECK(is_Valid(t));
    
       
}

TEST_CASE("to string test") {
  Time t{03,12,12, "am"};
  CHECK(to_String(t) == "03:12:12 am");
}

TEST_CASE("IS IT AM OR PM") {
  Time t{04,12,12, "am"};
  CHECK(is_am(t));
}

TEST_CASE("Operator ++"){
  Time t{04,12,12, "am"};
 
  //  CHECK(t+ 5);
  
  
}
