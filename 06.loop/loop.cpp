#include <iostream>
using namespace std;

int main()
{
    // Start for loop
    for (int i = 1; i <= 10; i++)
    {
        cout << "Hello World\n";
    }
    // End for loop


    // Start while loop

    // initialization expression
    int i = 1;

    // test expression
    while (i < 6)
    {
        cout << "Hello World\n";

        // update expression
        i++;
    }
    // End while loop


    // Start do while loop
    i = 2; // Initialization expression

    do
    {
        // loop body
        cout << "Hello World\n";

        // update expression
        i++;

    }  while (i < 1);   // test expression
    // End do while loop


    // Break loop using break
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == key) {
            cout << "5 found in array";
            break;
        }
    }

    // Continue in loop
    for (int i = 1; i <= 10; i++) {
        if (i == 6) //If i equals 6, continue to next
                    //iteration without printing
            continue;
        cout << i << " ";
    }

    return 0;
}
