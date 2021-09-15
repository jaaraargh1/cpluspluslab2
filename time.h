#ifndef time_H
#define time_H

struct Time
{
  int HH{23};
  int MM{59};
  int SS{59};
};

bool is_Valid(Time const& t);
#endif
