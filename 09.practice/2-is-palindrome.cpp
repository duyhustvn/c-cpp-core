#include <iostream>

using namespace std;

int main() {
  char str[] = "";

  cout << "Input a string: ";
  cin >> str;


  int left = 0, right = strlen(str) - 1;
  for (; left < right; ) {
    if (str[left] != str[right]) {
      cout << str << " is not a palindrome string" << endl;
      return 0;
      }
    left++;
    right--;
  }
  cout << str << " is palindrom string" << endl;
}
