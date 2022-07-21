#include <iostream>

using namespace std;

int main() {
  int num;

  cout << "Input a number: ";
  cin >> num;

  string binaries;
  do {
    int remainder = num % 2;
    binaries.insert(0, to_string(remainder));
    num = int(num / 2);
  } while(num);

  cout << "number: " << num << " -> binary: " << binaries << endl;
  return 1;
}
