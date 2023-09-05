// Reference: https://hpc-tutorials.llnl.gov/posix/passing_args/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define NUM_THREADS 8

void *PrintHello(void *threadID) {
  long taskID;
  sleep(1);
  taskID = *(long *)threadID;
  printf("Hello from thread %ld\n", taskID);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  for (long t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    int rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  /* The main thread is done, so we need to call pthread_exit explicitly to
   *  permit the working threads to continue even after main completes.
   */
  pthread_exit(NULL);
}
