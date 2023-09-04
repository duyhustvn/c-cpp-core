#include <stdio.h>

void display();

int main() {
  void (*p)(); /* The second pair () indicates that p is a pointer to a function
                * (*p) indicates that p is a pointer to a function that returns
                * nothing
                * if we drop () around *p, p will become a function that returns
                * a void*
                */
  p = display;
  (*p)();
  p();
}

void display() { printf("Hello world\n"); }
