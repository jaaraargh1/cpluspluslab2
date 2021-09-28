#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"
using namespace std;
 
TEST_CASE("Test Valid") {
  Time t{23, 20,19};
  Time t2{22,11,44};

    CHECK(is_Valid(t));
          
}

TEST_CASE("to string test") {
  Time t{03,12,12};
  Time t2{16,12,12};
  Time t3{13,12,12};
  CHECK(to_String(t, "am") == "03:12:12 am");
  CHECK(to_String(t2, "pm") == "04:12:12 pm");
  CHECK(to_String(t3, "24") == "13:12:12");

}

TEST_CASE("IS IT AM OR PM") {
  Time t{04,12,12};
  CHECK(is_am(t));
}


TEST_CASE("Operator ="){
  Time t1{04,12,12};
  Time t2{04,12,12};
  Time t3{06,23,23};
    CHECK(t1==t2);
    CHECK_FALSE(t1==t3);
}

TEST_CASE("Operator +"){
  Time t{04,12,12};
  Time t2{05,12,13};
  CHECK(t+3601 == t2);  
}

TEST_CASE("Operator -"){
  Time t{04,12,12};
  Time t2{03,12,11};
  t=t-3601;
  CHECK(t == t2);
}

TEST_CASE("Operator ++"){
  Time t{04,12,12};
  Time t2{04,12,13};
  Time t3{04,12,14};
  Time t4{04,12,12};
  CHECK(t++ == t4);//post
  cout << t;
  CHECK(t==t2);
  CHECK(++t==t3);
}

TEST_CASE("Operator --"){
  Time t{04,12,12};
  Time t2{04,12,11};
  Time t3{04,12,10};
  Time t4{04,12,12};
  CHECK(t-- == t4);
  CHECK(t == t2);
  CHECK(--t==t3);
}

TEST_CASE("Operator !="){
  Time t1{04,12,12};
  Time t2{04,12,12};
  Time t3{06,23,23};
    CHECK(t1!=t3);
    CHECK_FALSE(t1!=t2);
}


TEST_CASE("Operator <"){
  Time t1{04,12,12};
  Time t2{04,12,13};
  Time t3{04,12,11};
    Time t4{04,12,12};
    CHECK(t1<t2);
    CHECK_FALSE(t1<t4);
    CHECK_FALSE(t1<t3);
}

TEST_CASE("Operator >"){
  Time t1{04,12,12};
  Time t2{04,12,13};
  Time t3{04,12,11};
    CHECK(t1>t3);
    CHECK_FALSE(t1>t2);
}

TEST_CASE("Operator <="){
  Time t1{04,12,12};
  Time t2{04,12,13};
  Time t3{04,12,11};
  Time t4{04,12,12};
  CHECK(t1<=t2);
  CHECK_FALSE(t1<=t3);
  CHECK(t1<=t4);
}

TEST_CASE("Operator >="){
  Time t1{04,12,12};
  Time t2{04,12,13};
  Time t3{04,12,11};
  Time t4{04,12,12};
  CHECK(t1>=t3);
  CHECK_FALSE(t1>=t2);
  CHECK(t1>=t4);
}

TEST_CASE("Operator <<"){
  Time t{01,01,01};
  cout << t;
}

TEST_CASE("Operator >>"){
  Time t;
  Time t2{10,10,10};
  cin >> t;
  CHECK(t == t2);
}

