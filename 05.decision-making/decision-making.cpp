#include<iostream>
using namespace std;

int main()
{
    int i = 20;

    if (i == 10)
        cout<<"i is 10";
    else if (i == 15)
        cout<<"i is 15";
    else if (i == 20)
        cout<<"i is 20";
    else
        cout<<"i is not present";

    cout << endl;
    int x = 2;
    switch (x) {
      case 1: cout << "Choice is 1 \n";
        break;
      case 2: cout << "Choice is 2 \n";
        break;
      case 3: cout << "Choice is 3 \n";
        break;
      default: cout << "Choice other than 1, 2, and 3\n";
        break;
    }

    return 1;
}
