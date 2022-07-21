#include <iostream>

using namespace std;

void memAlloc() {
  // this pointer will hold the
  // base address of the block created
  int *ptr;
  int n, i = 0;

  // Get the number of elements for the array
  n = 5;
  cout << "Enter the number of elements: " << n << endl;

  // dynamic allocate memory using malloc()
  ptr = (int*)malloc(n * sizeof(int));

  // check if the memory has been successfully allocated by malloc or not
  if (ptr == NULL) {
    cout << "Memory not allocated" << endl;
    exit(0);
  } else {
    cout << "Memory successfully allocated using malloc" << endl;

    // Get the elements of the array
    for (i = 0; i < n; i++) {
      ptr[i] = i+1;
    }


    // print the elements of array
    cout << "The elements of the array are: ";
    for (i = 0; i < n; i++) {
      cout << ptr[i] << ", ";
    }
  }
  free(ptr);
  cout << endl;
}

void contiguousAlloc() {
  // this pointer will hold the
  // base address of the block created
  int *ptr;
  int n, i, sum = 0;

   // Get the number of elements for the array
  n = 5;
  cout << "Enter the number of elements: " << n << endl;

  ptr = (int *)calloc(n, sizeof(int));
  // check if the memory has been successfully allocated
  if (ptr == NULL) {
    cout << "Memory not calloc" << endl;
    exit(0);
  }

  cout << "Memory successfully allocated using calloc" << endl;

  // Get the elements of the array
  for (i = 0; i < n; i++) {
    ptr[i] = i + 1;
  }

  // print the elements of the array
  cout << "The element of the array are: ";
  for (i = 0; i < n; i++) {
    cout << ptr[i] << ", ";
  }

  free(ptr);
  cout << endl;
}

void reAlloc() {
  // this pointer will hold the
  // base address of the block created
  int *ptr;
  int n, i, sum = 0;

   // Get the number of elements for the array
  n = 5;
  cout << "Enter the number of elements: " << n << endl;

  ptr = (int *)calloc(n, sizeof(int));
  // check if the memory has been successfully allocated
  if (ptr == NULL) {
    cout << "Memory not calloc" << endl;
    exit(0);
  }

  cout << "Memory successfully allocated using calloc" << endl;

  // Get the elements of the array
  for (i = 0; i < n; i++) {
    ptr[i] = i + 1;
  }

  // print the elements of the array
  cout << "The element of the array are: ";
  for (i = 0; i < n; i++) {
    cout << ptr[i] << ", ";
  }

  n = 10;
  cout << endl << endl;

  // Dynamic re-allocated memory using realloc()
  ptr = (int*)realloc(ptr, n * sizeof(int));

  cout << "Memory successfully re-allocated using realloc" << endl;

  // Get the new elements of the array
  for (i = 5; i < n; i++) {
    ptr[i] = i + 1;
  }

  // Print the elements of the array
  for (i = 0; i < n; i++) {
    cout << ptr[i] << ", ";
  }
  cout << endl << endl;


  free(ptr);
  cout << endl;
}


int main() {
  memAlloc();
  contiguousAlloc();
  reAlloc();

  return 0;
}
