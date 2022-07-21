#include <iostream>

using namespace std;

int sum(int a, int b) {
  return a + b;
}

int main() {
  int a = 10, b = 20;

  int s = sum(a, b);
  cout << "sum of " << a << " and " << b << " is: " << s << endl;
  return 0;
}
