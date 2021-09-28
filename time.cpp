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

string to_String(Time const& t, string ampm){
  
  stringstream ss;
  if (ampm == "am" || ampm == "pm") {
    if (t.HH < 12) {
      ss << setw(2) << setfill('0') << t.HH << ":"  << setw(2)
	 << setfill('0') << t.MM << ":"<< setw(2) << setfill('0')
	 << t.SS << " " << "am"; 
      return ss.str();
    } else if (t.HH == 12) {
      ss << setw(2) << setfill('0') << t.HH  << ":"  << setw(2)
	 << setfill('0') << t.MM << ":"<< setw(2) << setfill('0')
	 << t.SS << " " << "pm";
      return ss.str();
    } else if (t.HH == 00) {
      ss << setw(2) << setfill('0') << t.HH+12 << ":"  << setw(2)
	 << setfill('0') << t.MM << ":"<< setw(2) << setfill('0')
	 << t.SS << " " << "am";
      return ss.str();
    } else {
      ss << setw(2) << setfill('0') << t.HH-12  << ":"  << setw(2)
	 << setfill('0') << t.MM << ":"<< setw(2) << setfill('0')
	 << t.SS << " " << "pm";
      return ss.str();
    }
  } else {
    ss << setw(2) << setfill('0') << t.HH << ":"  << setw(2)
       << setfill('0') << t.MM << ":"<< setw(2) << setfill('0')
       << t.SS; 
    return ss.str();
  }
}

bool is_am(Time const& t){
  if (t.HH < 12) {
    return true;
  }
  return false;  
}

//Time normalize(Time tmp, int totSec){

//  tmp.SS = totSec%60;
//  tmp.MM = (totSec/60)%60;
//  tmp.HH = (totSec/3600)%24;
//  return tmp;
//}


Time operator + (Time& t, int n) {
  Time tmp{t};
  int totSec{t.HH*3600+t.MM*60+t.SS+n};
  t.SS = totSec%60;
  t.MM = (totSec/60)%60;
  t.HH = (totSec/3600)%24;
  return t;

}

Time operator -(Time& t, int n) {
  Time tmp{t};
  int totSec{t.HH*3600+t.MM*60+t.SS-n};
  t.SS = totSec%60;
  t.MM = (totSec/60)%60;
  t.HH = (totSec/3600)%24;
  return t;

}
//pre
Time& operator ++(Time& t) {

  int totSec{t.HH*3600+t.MM*60+t.SS+1};
  t.SS = totSec%60;
  t.MM = (totSec/60)%60;
  t.HH = (totSec/3600)%24;
  return t;

}
//pre
Time& operator --(Time& t) {
  Time tmp{t};
  int totSec{t.HH*3600+t.MM*60+t.SS-1};
  t.SS = totSec%60;
  t.MM = (totSec/60)%60;
  t.HH = (totSec/3600)%24;
  return t;

}
//post
Time operator ++(Time& t, int) {
  Time tmp{t};  
  int totSec{t.HH*3600+t.MM*60+t.SS+1};
  t.SS = totSec%60;
  t.MM = (totSec/60)%60;
  t.HH = (totSec/3600)%24;
  return tmp;

}
//post
Time operator --(Time& t, int) {
  Time tmp{t};  
  int totSec{t.HH*3600+t.MM*60+t.SS-1};
  t.SS = totSec%60;
  t.MM = (totSec/60)%60;
  t.HH = (totSec/3600)%24;
  return tmp;

}

bool operator ==(Time const& t1, Time const& t2) {
    if (t1.SS != t2.SS)   {
    return false;
  }
  if (t1.MM != t2.MM)   {
    return false;
  } 
  if (t1.HH != t2.HH)   {
    return false;
  }
  return true;     
}

bool operator !=(Time const& t1, Time const& t2) {
    if (t1.SS == t2.SS)   {
    return false;
  }
  if (t1.MM == t2.MM)   {
    return false;
  } 
  if (t1.HH == t2.HH)   {
    return false;
  }
  return true;     
}

bool operator <(Time const& t1, Time const& t2) {
  if (t1.HH > t2.HH)   {
    return false;
  }
  if (t1.MM > t2.MM)   {
    return false;
  } 
  if (t1.SS >= t2.SS)   {
    return false;
  }
  return true;     
}

bool operator >(Time const& t1, Time const& t2) {
  if (t1.HH < t2.HH)   {
    return false;
  }
  if (t1.MM < t2.MM)   {
    return false;
  } 
  if (t1.SS <= t2.SS)   {
    return false;
  }
  return true;     
}

bool operator <=(Time const& t1, Time const& t2) {
  if (t1.HH > t2.HH)   {
    return false;
  }
  if (t1.MM > t2.MM)   {
    return false;
  } 
  if (t1.SS > t2.SS)   {
    return false;
  }
  return true;     
}

bool operator >=(Time const& t1, Time const& t2) {
  if (t1.HH < t2.HH)   {
    return false;
  }
  if (t1.MM < t2.MM)   {
    return false;
  } 
  if (t1.SS < t2.SS)   {
    return false;
  }
  return true;     
}

ostream & operator <<(ostream &os, Time const& t){
  
  os << setfill('0') << setw(2) << t.HH << ":"
     << setw(2)<< t.MM << ":" << setw(2) << t.SS;
  return os;
}

istream & operator >> (istream &is, Time &t){

  is >> t.HH;
  is.ignore(1);
  is >> t.MM;
  is.ignore(1);
  is >> t.SS;
  return is;
}

