#include <iostream>

using namespace std;

enum week {
  Mon,
  Tue,
  Wed,
  Thur,
  Fri,
  Sat,
  Sun
};

enum state {
  working = 1,
  idle = 0
};

enum dayInWeek {
  sunday = 1,
  monday,
  tuesday = 5,
  wednesday,
  thursday = 10,
  friday,
  saturday
};

int main() {
  week day;
  day = Mon;
  cout << day << endl;

  state s = working;
  cout << s << endl;

  dayInWeek dik1 = sunday;
  dayInWeek dik2 = monday;
  dayInWeek dik3 = tuesday;
  dayInWeek dik4 = wednesday;

  cout << dik1 << " " << dik2 << " " << dik3 << " " << dik4 << endl;

  return 1;
}
