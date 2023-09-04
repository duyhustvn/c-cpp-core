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

char *messages[NUM_THREADS];

void *PrintHello(void *threadId) {
  long taskId;

  sleep(1);

  taskId = (long)threadId;
  printf("Thread %ld: %s\n", NUM_THREADS - 1 - taskId, messages[taskId]);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  long taskids[NUM_THREADS];
  int rc;

  messages[0] = "English: Hello World";
  messages[1] = "French: Bonjour, le monde!";
  messages[2] = "Spanish: Hola al mundo";
  messages[3] = "Klingon: Nuq neH!";
  messages[4] = "German: Guten Tag, Welt!";
  messages[5] = "Russian: Zdravstvuyte, mir!";
  messages[6] = "Japan: Sekai e konnichiwa!";
  messages[7] = "Latin: Orbis, te saluto!";

  for (long t = 0; t < NUM_THREADS; t++) {
    taskids[t] = NUM_THREADS - 1 - t;
    printf("Creating thread %ld\n", t);
    /* p_thread_create accepts 4 arguments
    ** thread: An opaque, unique identifier for the new thread returned by the
    ** subroutine.
    ** attr: An opaque attribute object that may be used to set thread
    ** attributes. You can specify a thread attributes object, or NULL for the
    ** default values.
    ** start_routine: the C routine that the thread will execute once it is
    ** created.
    ** arg: A single argument that may be passed to start_routine. It must be
    ** passed by reference as (void *). NULL may be used if no argument is to
    ** be passed.
    */
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)taskids[t]);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
