#include <iostream>

using namespace std;

// int add(int y=10, int x);   //not allowed
// int add(int x, int y=10);   //allowed

int add(int x, int y=0) {
  return x + y;
}

int main() {
  cout << add(6, 8) << endl;
  cout << add(6) << endl;
  return 0;
}
