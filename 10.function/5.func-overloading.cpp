#include <iostream>

using namespace std;

int add(int x, int y) {return x + y;}

string add(string x, string y) { return x + y; }

int main() {
  // add 2 numbers
  cout << add(7, 8) << endl;

  // concat 2 strings
  cout << add("Hello", "motherfucker") << endl;

  return 1;
}
