#include <iostream>

using namespace std;

inline int max_int(int x, int y) {return (x > y) ? x : y;}

int main() {
  cout << max_int(5,6) << endl;
  cout << max_int(8,6) << endl;
  return 0;
}
