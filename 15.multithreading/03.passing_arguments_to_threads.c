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

typedef struct threadData_ {
  int threadId;
  int sum;
  char *message;
} threadData;

threadData threadDataArray[NUM_THREADS];

void *PrintHello(void *threadArg) {
  threadData *data;
  sleep(1);
  data = (threadData *)threadArg;

  int taskID = data->threadId;
  int sum = data->sum;
  char *msg = data->message;
  printf("Thread %d: %s Sum=%d\n", taskID, msg, sum);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int *taskIds[NUM_THREADS];

  int sum = 0;
  messages[0] = "English: Hello World";
  messages[1] = "French: Bonjour, le monde!";
  messages[2] = "Spanish: Hola al mundo";
  messages[3] = "Klingon: Nuq neH!";
  messages[4] = "German: Guten Tag, Welt!";
  messages[5] = "Russian: Zdravstvuyte, mir!";
  messages[6] = "Japan: Sekai e konnichiwa!";
  messages[7] = "Latin: Orbis, te saluto!";

  for (int t = 0; t < NUM_THREADS; t++) {
    sum += t;
    threadDataArray[t].threadId = t;
    threadDataArray[t].sum = sum;
    threadDataArray[t].message = messages[t];
    printf("Create thread %d\n", t);

    /*
    ** The pthread_create() routine allows the programmer to pass one argument
    ** to the thread start routine. For cases where multiple arguments must be
    ** passed,
    ** this limitation is easily overcome by creating a structure containing all
    ** of the arguments, then passing a pointer to that structure in the
    ** pthread_create() routine.

    ** All arguments must be passed by reference and cast to (void *)
    */
    int rc = pthread_create(&threads[t], NULL, PrintHello,
                            (void *)&threadDataArray[t]);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  pthread_exit(NULL);
}
