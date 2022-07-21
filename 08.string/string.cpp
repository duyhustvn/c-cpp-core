#include <iostream>

using namespace std;

int main() {
  /*
    C-style (character arrays and literals)
   */

  char str[] = "hello";

  for (int i = 0; i < strlen(str); i++) {
    cout << (char)(str[i] - 'a' + 'A');
  }

  cout << endl;

  // strcat
  char src[] = {'s', 'o', 'u', 'r', 'c', 'e'};
  char dest[] = "destination";
  cout << "strcat" << endl;
  cout << strcat(dest, src) << endl;


  // strcmp
  char str1[] = "abc";
  char str2[] = "abcd";
  char str3[] = "abb";
  cout << "strcmp" << endl;
  cout << strcmp(str1, str2) << endl;
  cout << strcmp(str1, str3) << endl;
  cout << strcmp(str2, str3) << endl;

  // strcpy
  char dest1[100];
  char src1[] = "Hello World";
  strcpy(dest1, src1);
  cout << "Source: " << src1 << " Des: " << dest1 << endl;

  char dest2[] = "Wtf";
  char src2[] = "Hello World";
  strcpy(dest2, src2);
  cout << "Source: " << src2 << " Des: " << dest1 << endl;


  cout << "strstr" << endl;
  char s1[] = "Hellomotherfucker =))";
  char s2[] = "fuck";
  char *p;

  p = strstr(s1, s2);
  if (p) {
    cout << "First occurrence of string ''" << s2 << "' \n in '" << s1 << "' is '" << p << "'" << endl;
  } else {
    cout << "String not found\n";
  }


  /*
    String Class in C++ STL (Standard Template Class)
   */


  // Declare String
  string str4;

  // Taking input from user
  cout << "input a string: ";
  cin >> str4;

  cout << str4 << " " << str4.length() << endl;

  cout << "Iterator" << endl;
  string::iterator it;
  for (it = str4.begin(); it != str4.end(); it++) {
    cout << *it;
  }
  cout << endl;

  string str5 = "fuck";
  cout << "Length of String '" << str5 << "' is: " << str5.size() << endl;

  str5.clear();
  if (str5.empty()) {
    cout << "String is empty\n";
  }

  string s6 = "Hello Everyone";
  string s7 = "motherfucker";

  // Insert s7 at index 5 of s6
  s6.insert(5, s7);
  cout << "inserted result: " << s6 << endl;

  // push_back append character to the end.
  // cannot append string, character only
  s6.push_back(' ');
  s6.push_back('=');
  s6.push_back('_');
  s6.push_back('=');
  cout << "push_back result: " << s6 << endl;

  s6.pop_back();
  s6.pop_back();
  s6.pop_back();
  cout << "pop_back result: " << s6 << endl;

  // find func
  cout << "find function" << endl;
  unsigned long isFound = s6.find("fuck");
  if (isFound != string::npos) {
    cout << "found: " << isFound << endl;
  } else {
    cout << "Not found" << endl;
  }

  // substr func
  // 1st argument is position
  // 2nd argument is no. of character
  cout << "substr: " << s6.substr(5, 3) << endl;

  //If 2nd argument is not provided, substring
  // is generated from position to end to string
  cout << "substr: " << s6.substr(5) << endl;

  return 0;
}
