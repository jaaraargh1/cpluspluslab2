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
Time operator +(Time t, int n);
#endif
