#include <iostream>

using namespace std;

int main() {
  unsigned long long int x = 1234567890;

  unsigned long long int tmp = x;

  int numberOfDigits = 0;

  do {
    numberOfDigits++;
    tmp/= 10;
  } while(tmp);

  cout << tmp << endl;
  cout << numberOfDigits << endl;

  return 0;
}
