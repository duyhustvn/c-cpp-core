// Reference: https://hpc-tutorials.llnl.gov/posix/creating_and_terminating/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *threadId) {
  long tid;
  tid = (long)threadId;
  printf("Hello World! It's me thread %ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc; // return code
  for (long t = 0; t < NUM_THREADS; t++) {
    printf("In main: creating thread %ld\n", t);
    /* p_thread_create accepts 4 arguments
    ** thread: An opaque, unique identifier for the new thread returned by the
    ** subroutine.
    ** attr: An opaque attribute object that may be used to set thread
    ** attributes. You can specify a thread attributes object, or NULL for the
    ** default values.
    ** start_routine: the C routine that the thread will execute once it is
    ** created.
    ** arg: A single argument that may be passed to start_routine. It must be
    ** passed by reference as (void *). NULL may be used if no argument is to be
    ** passed.
    */
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
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
