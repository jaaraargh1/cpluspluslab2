#ifndef time_H
#define time_H

struct Time
{
  int HH{};
  int MM{};
  int SS{};
  std::string p {};
};

bool is_Valid(Time const& t);
std::string to_String(Time const& t);
bool is_am(Time const& t);
Time normalize(Time tmp, int totSec);
Time operator +(Time const& t, int n);
Time operator -(Time const& t, int n);
Time operator ++(Time const& t);
Time operator --(Time const& t);
Time operator ++(Time const& t, int);
Time operator --(Time const& t, int);
bool operator ==(Time const& t1, Time const& t2);
bool operator !=(Time const& t1, Time const& t2);
bool operator <(Time const& t1, Time const& t2);
bool operator >(Time const& t1, Time const& t2);
bool operator <=(Time const& t1, Time const& t2);
bool operator >=(Time const& t1, Time const& t2);
std::ostream & operator <<(std::ostream &os, Time const& t);
std::istream & operator >>(std::istream &is, Time &t);
#endif
