#include <iostream>

using namespace std;

int main() {
  int a = 12, b = 6;

  a += b;
    cout << "Add & Assign: "<< a <<"\n";

    a -= b;
    cout << "Subtract & Assign: " << a << "\n";

    a *= b;
    cout << "Multiply & Assign: " << a << "\n";

    a /= b;
    cout << "Divide & Assign: " << a << "\n";


// a: 1100, b: 0110, c: 1001, d: 0010
    a = 12, b = 6;
     int c = 2, d = 9, e = 1;

    a &= b;
    //   1100
    // & 0110
    //-------
    //   0100 (4)
    cout << "AND & Assign: "<< a <<"\n";

    a |= c;
    //   0100
    // | 0010
    //-------
    //   0110 (6)
    cout << "OR & Assign: " << a << "\n";

    a ^= d;
    //   0110
    // ^ 1001
    //-------
    //   1111 (15)
    cout << "XOR & Assign: " << a << "\n";

    a <<= e;
    //    1111
    // << 0001
    //--------
    //   11110 (30)
    cout << "Left-shift & Assign: " << a << "\n";

    a >>= e;
    //    11110
    // >> 00001
    //---------
    //    01111 (15)
    cout << "Right-shift & Assign: " << a << "\n";

    return 0;
}
