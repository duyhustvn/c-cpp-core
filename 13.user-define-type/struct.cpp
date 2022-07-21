#include <iostream>

using namespace std;

struct Employee {
  string name; // name of person
  int age; // age of person
  double salary; // salary of person
  bool remote; // work remote or not
};

void structPadding() {
  struct A {
    int x; // size of int is 4 bytes
    double z; // size of double is 8 bytes
    short int y; // size of short int is 2 bytes
  };

  cout << "Size of struct A expected: " << 4 + 8+ 2 << " reliaty: " << sizeof(struct A) << endl;

  struct B {
    short int y; // size of short int is 2 bytes
    int x; // size of int is 4 bytes
    double z; // size of double is 8 bytes
  };

  cout << "Size of struct B expected: " << 4 + 8+ 2 << " reliaty: " << sizeof(struct B) << endl;

  struct C {
    int x; // size of int is 4 bytes
    short int y; // size of short int is 2 bytes
    double z; // size of double is 8 bytes
  };

  cout << "Size of struct C expected: " << 4 + 8+ 2 << " reliaty: " << sizeof(struct C) << endl;

  struct D {
    char y; // size of short int is 1 bytes
    int x; // size of int is 4 bytes
    char z; // size of double is 1 bytes
  };

  cout << "Size of struct D expected: " << 4 + 1 + 1 << " reliaty: " << sizeof(struct D) << endl;

  struct E {
    int x; // size of int is 4 bytes
    char y; // size of short int is 1 bytes
    char z; // size of double is 1 bytes
  };

  cout << "Size of struct E expected: " << 4 + 1 + 1 << " reliaty: " << sizeof(struct E) << endl;



}

int main() {
  Employee e = {"David", 24, 2.5, true};

  cout << "Name: " << e.name << endl;
  cout << "Age: " << e.age << endl;
  cout << "Salary: " << e.salary << endl;
  cout << "Is remote?: " << e.remote << endl;

  Employee* eptr = &e;

  // Access using structure pointer
  cout << "Pointer Access: " << eptr->name << endl;

  structPadding();
}
