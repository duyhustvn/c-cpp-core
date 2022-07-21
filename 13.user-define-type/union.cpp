#include <iostream>

using namespace std;

union test {
  int x, y;
};

// Unions are useful in cases where one needs to conserve data.
// e.g. Suppose we want to implement a binary tree data structure where each leaf node has a double data value,
// while each internal node has pointers to two children, but no data.
// If we declare this as:
// struct NODE {
//     struct NODE* left;
//     struct NODE* right;
//     double data;
// };

void usecase() {
  struct Node {
    bool is_leaf;
    union {
      struct {
        struct Node* left;
        struct Node* right;
      } internal;
    } info;
  };
}

int main() {
  test t;
  t.x = 2;
  cout << t.x << " " << t.y << endl;

  t.y = 3;
  cout << t.x << " " << t.y << endl;

  return 0;
}
