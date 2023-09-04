
#include <stdio.h>
#include <string.h>

void dbl(int *);
void tple(int *);
void qdpl(int *);

void callFunctions(int num, int arr[]) {
  void (*p[3])(int *) = {dbl, tple, qdpl};
  // p[0] = dbl;
  // p[1] = tple;
  // p[2] = qdpl;

  int i;
  for (i = 0; i < 3; i++) {
    p[i](&num);
    arr[i] = num;
  }
}

void dbl(int *n) { *n = (*n) * (*n); }

void tple(int *n) { *n = (*n) * (*n) * (*n); }

void qdpl(int *n) { *n = (*n) * (*n) * (*n) * (*n); }

int main() {
  int arr[3] = {0, 0, 0};
  int num = 2;
  callFunctions(num, arr);
  for (int i = 0; i < 3; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
