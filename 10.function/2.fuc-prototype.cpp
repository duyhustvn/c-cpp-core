#include <iostream>

using namespace std;

// prototype declaration
int max(int a, int b);
int min(int, int);
void swapByValue(int, int);
void swapByReference(int &a, int &b);

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

void swapByValue(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swapByReference(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}


int main() {
  int a = 10, b = 11;
  cout << "max between " << a << " and " << b << " is: " << max(a, b) << endl;
  cout << "min between " << a << " and " << b << " is: " << min(a, b) << endl;

  cout << "before swap by value a: " << a << " b: " << b << endl;
  swapByValue(a, b);
  cout << "after swap by value a: " << a << " b: " << b << endl;


  cout << "before swap by reference a: " << a << " b: " << b << endl;
  swapByReference(a, b);
  cout << "after swap by reference a: " << a << " b: " << b << endl;
  return 1;
}
