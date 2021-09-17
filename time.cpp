#include <iostream>
#include "time.h"
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

bool is_Valid(Time const& t){
 
  if ((t.SS > 59 || t.SS < 0))   {
    return false;
  }

  if ((t.MM > 59 || t.MM < 0))   {
    return false;
  } 

  if ((t.HH > 23 || t.HH < 0 ))   {
    return false;
  }

  return true;
     
}
/*
operator >> (istream & is){
  int HH{};
  int MM{};
  int SS{};
  is >> HH;
  is.ignore(1);
  is >> MM;
  is.ignore(1);
  is >> SS;
} */
string to_String(Time const& t){
  
  stringstream ss;
  
  ss << setw(2) << setfill('0') << t.HH  << ":"  << setw(2) << setfill('0') << t.MM << ":"<< setw(2) << setfill('0') << t.SS << " " << t.p; 
  return ss.str();
}

bool is_am(Time const& t){
  if ( t.p == "am") {
    return true;
  }
  return false;  
}

Time operator + (Time t, int n) {
  int tmp{};
 		 
t.MM = t.SS / 60;
t.HH= t.MM / 60;

 return t;
}
  
