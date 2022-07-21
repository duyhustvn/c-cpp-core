#include <iostream>

using namespace std;

void swap(int &first, int &second) {
  int tmp = first;
  first = second;
  second = tmp;
}

int main() {
  int a = 2, b = 3;
  cout << "Before swap a: " << a << " b: "  << b << endl;
  swap(a, b);
  cout << "After swap a: " << a << " b: "  << b << endl;
  return 0;
}
