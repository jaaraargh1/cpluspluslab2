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

TEST_CASE("Operator +"){
  Time t{04,12,12, "am"};
  t=t+3601;
    CHECK(to_String(t) == "05:12:13 am");  
}

TEST_CASE("Operator -"){
  Time t{04,12,12, "am"};
  t=t-3601;
  CHECK(to_String(t) == "03:12:11 am");
}

TEST_CASE("Operator ++"){
  Time t{04,12,12, "am"};
  t=t++;
  CHECK(to_String(t) == "04:12:13 am");
  t=++t;
  CHECK(to_String(t) == "04:12:14 am");
}

TEST_CASE("Operator --"){
  Time t{04,12,12, "am"};
  t=t--;
  CHECK(to_String(t) == "04:12:11 am");
  t=--t;
  CHECK(to_String(t) == "04:12:10 am"); 
}

TEST_CASE("Operator ="){
  Time t1{04,12,12, "am"};
  Time t2{04,12,12, "am"};
  Time t3{06,23,23, "am"};
    CHECK(t1==t2);
    CHECK_FALSE(t1==t3);
}

TEST_CASE("Operator !="){
  Time t1{04,12,12, "am"};
  Time t2{04,12,12, "am"};
  Time t3{06,23,23, "am"};
    CHECK(t1!=t3);
    CHECK_FALSE(t1!=t2);
}


TEST_CASE("Operator <"){
  Time t1{04,12,12, "am"};
  Time t2{04,12,13, "am"};
  Time t3{04,12,11, "am"};
    Time t4{04,12,12, "am"};
    CHECK(t1<t2);
    CHECK_FALSE(t1<t4);
    CHECK_FALSE(t1<t3);
}

TEST_CASE("Operator >"){
  Time t1{04,12,12, "am"};
  Time t2{04,12,13, "am"};
  Time t3{04,12,11, "am"};
    CHECK(t1>t3);
    CHECK_FALSE(t1>t2);
}

TEST_CASE("Operator <="){
  Time t1{04,12,12, "am"};
  Time t2{04,12,13, "am"};
  Time t3{04,12,11, "am"};
  Time t4{04,12,12, "am"};
  CHECK(t1<=t2);
  CHECK_FALSE(t1<=t3);
  CHECK(t1<=t4);
}

TEST_CASE("Operator >="){
  Time t1{04,12,12, "am"};
  Time t2{04,12,13, "am"};
  Time t3{04,12,11, "am"};
  Time t4{04,12,12, "am"};
  CHECK(t1>=t3);
  CHECK_FALSE(t1>=t2);
  CHECK(t1>=t4);
}

TEST_CASE("Operator <<"){
  Time t{01,01,01, "am"};
  cout << t;
}

TEST_CASE("Operator >>"){
  Time t;
  cin >> t;
  t.p = ("am");
  CHECK(to_String(t) == "10:08:05 am");
}
