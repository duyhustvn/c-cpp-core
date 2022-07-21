#include <iostream>

using namespace std;

int add(int x, int y) {
  return x + y;
}

string add(string x, string y) {
  return x + y;
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int fun1();
double fun2();
int fun3(int);


//3rd argument is a function pointer
void sort(int a[], int n, bool (*compare)(int, int))
{
    int i,j;
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
            if (!compare(a[j], a[j+1]))
                swap(a[j], a[j+1]);
}


bool desc(int x, int y) {
  return x > y;
}


bool asc(int x, int y) {
  return x < y;
}

int main() {

  // Assign integer add() function to function pointer
  int (*func_ptr_int)(int, int) = add;

  // Assign string add() function to function pointer
  string (*func_ptr_str)(string, string) = add;

  // Calling using function pointer
  cout << func_ptr_int(6, 4) << endl;

  cout << func_ptr_str("hello", "motherfucker") << endl;


  // int (*fun_ptr)() = fun1; //valid
  // fun_ptr = fun2;  //invalid (return-type mismatch)
  // fun_ptr = fun3;  //invalid (argument list mismatch)

  int arr[] = {5, 2, 4, 6};
  int i;
  cout << "Before sort: " << endl;
  for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  sort(arr, sizeof(arr)/sizeof(arr[0]), desc);

  cout << "After sort: " << endl;
  for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    cout << arr[i] << " ";
  }



  cout << endl;
  return 0;
}

