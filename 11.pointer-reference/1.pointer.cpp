#include <iostream>

using namespace std;

void increase(void *data, int ptrsize) {
  if (ptrsize == sizeof(int)) {
    int *ptrint;
    ptrint = (int*)data;
    (*ptrint)++;
  } else if (ptrsize == sizeof(char)) {
    char *ptrchar;
    ptrchar = (char*)data;
    (*ptrchar)++;
  }
}

void arrayPointer() {
  // Declare an array
  int val[3] = {5, 10, 20};

  // declare pointer value
  int *ptrArr;

  ptrArr = val;

  cout << "Element of the array are: ";
  cout << ptrArr[0] << " " << ptrArr[1] << " " << ptrArr[2] << endl;
}

void stringPointer() {
  char s[] = "hello";
  const char *ptrStr1 = "friend";
  char *ptrStr;
  ptrStr = s;

  cout << *ptrStr << *(ptrStr+1) << endl;
  cout << *ptrStr1 << *(ptrStr1+1) << endl;
}

// NULL pointer
void func(int x) {cout << "Integer Call: " << x << endl;}
void func(int *x) {cout << "Pointer Call: " << x << endl;}

void nullpointer() {
  int *p = NULL;

  func(0); // Integer Call: 0
  func(p); // Pointer Call: 0
  // func(NULL); // amniguity issue cause NULL is 0 so it may mean int as well as int*
  func(nullptr); //
}

int main() {
  int p = 20;

  // declare pointer variable
  int *ptr;

  // note tht data type of ptr and p must be the same
  ptr = &p;

  cout << "Value at ptr = " << ptr << endl;
  cout << "Value at p = " << p << endl;
  cout << "Value at *ptr = " << *ptr << endl;

  arrayPointer();

  // Pointer to string
  stringPointer();

  // VOID POINTER
  char c = 'x';

  int i = 10;

  increase(&i, sizeof(i));
  cout << "The new value of i is: " << i << endl;

  increase(&c, sizeof(c));
  cout << "The new value of c is: " << c << endl;


  nullpointer();
  return 1;
}
