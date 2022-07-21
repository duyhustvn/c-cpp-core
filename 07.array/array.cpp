#include <iostream>
using namespace std;

int main() {
  int arr[5];
  arr[0] = 5;
  arr[2] = -10;
  arr[3/2] = 2;
  arr[3] = arr[0];

  cout << arr[0] << " " << arr[1] << " " << " " << arr[2] << " " << arr[3] << endl;


  // This C++ program compiles fine
  // as index out of bound
  // is not checked in C++.
  int arr1[2];
  cout << arr1[0] << " " << arr1[3] << " " << arr1[-2];

  // an array of 10 integers.  If arr[0] is stored at
  // address x, then arr[1] is stored at x + sizeof(int)
  // arr[2] is stored at x + sizeof(int) + sizeof(int)
  // and so on.
  int arr2[5], i;

  cout << "Size of int in this compiler is: " << sizeof(int) << endl;
  for (i = 0; i < 5; i++) {
    // The use of '&' before a variable name, yields
    // address of variable
    cout << "Address arr2[" << i << "] is " << &arr2[i] << endl;
  }

  return 0;
}
