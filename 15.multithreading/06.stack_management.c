// Reference: https://hpc-tutorials.llnl.gov/posix/stack_management/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include <bits/pthreadtypes.h>

#define NUM_THREADS 5
#define N 1000
#define MEG_EXTRA 1000000

pthread_attr_t attr;

void *dowork(void *threadID) {
  double A[N][N];
  long tid = (long)threadID;
  size_t myStackSize;

  pthread_attr_getstacksize(&attr, &myStackSize);
  printf("Thread %ld: stack size = %li bytes\n", tid, myStackSize);

  for (long i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = ((i * j) / 3.452) + (N - i);
    }
  }

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  size_t stackSize;

  pthread_attr_init(&attr);
  pthread_attr_getstacksize(&attr, &stackSize);
  printf("Default stack size: %li bytes ~ %f mb \n", stackSize,
         (double)stackSize / 1024000);

  stackSize = sizeof(double) * N * N + MEG_EXTRA;
  printf("Amount of stack needed per thread = %li\n", stackSize);
  pthread_attr_setstacksize(&attr, stackSize);

  printf("Creating threads with stack size = %li bytes\n", stackSize);
  for (long t = 0; t < NUM_THREADS; t++) {
    int rc = pthread_create(&threads[t], &attr, dowork, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  printf("Create %d threads.\n", NUM_THREADS);
  pthread_exit(NULL);
}
