// Reference: https://hpc-tutorials.llnl.gov/posix/example_using_cond_vars/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <bits/pthreadtypes.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define NUM_THREADS 3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;

pthread_mutex_t countMutex;
pthread_cond_t countThresholdCv;

void *incCount(void *t) {
  long myID = (long)t;
  for (int i = 0; i < TCOUNT; i++) {
    pthread_mutex_lock(&countMutex);
    count++;
    /*
      Check the value of count and signal waiting thread when condition is
      reached. Note that this occurs while mutex is locked
     */
    if (count == COUNT_LIMIT) {
      printf("incCount(): thread %ld, count = %d -- threshold reached", myID,
             count);
      // https://hpc-tutorials.llnl.gov/posix/man/pthread_cond_signal.txt
      pthread_cond_signal(&countThresholdCv);
      printf("Just sent signal.\n");
    }

    printf("incCount(): thread %ld, count = %d -- unlocking mutex\n", myID,
           count);
    pthread_mutex_unlock(&countMutex);

    /* Do some work so threads can alternate on mutex lock */
    sleep(1);
  }
  pthread_exit(NULL);
}

void *watchCount(void *t) {
  long myID = (long)t;
  printf("Starting watchCount(): thread %ld\n", myID);
  /*
    Lock mutex and wait for signal. Note that the pthread_cond_wait routine
    wil automatically and atomically unlock mutex while it waits.
    Also, note that if COUNT_LIMIT is reached before this routine is run by
    the waiting thread, the loop will be skipped to prevent pthread_cond_wait
    from never returning
  */
  pthread_mutex_lock(&countMutex);
  while (count < COUNT_LIMIT) {
    printf("watchCount(): thread %ld Count = %d. Going into wait...\n", myID,
           count);
    // https://hpc-tutorials.llnl.gov/posix/man/pthread_cond_wait.txt
    pthread_cond_wait(&countThresholdCv, &countMutex);
    printf("watchCount(): thread %ld Condition signal received. Count = %d\n",
           myID, count);
  }
  printf("watchCount(): thread %ld Updating value of count ...\n", myID);
  count += 125;
  printf("watchCount(): thread %ld count now  = %d \n", myID, count);
  printf("watchCount(): thread %ld Unlocking mutex \n", myID);
  pthread_mutex_unlock(&countMutex);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  long t1 = 1, t2 = 2, t3 = 3;
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;

  /* Initialize mutex and condition variable objects */
  pthread_mutex_init(&countMutex, NULL);
  pthread_cond_init(&countThresholdCv, NULL);

  /* For portability, explicity create threads in a joinable state */
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&threads[0], &attr, watchCount, (void *)t1);
  pthread_create(&threads[1], &attr, incCount, (void *)t2);
  pthread_create(&threads[2], &attr, incCount, (void *)t3);

  /* Wait for all threads to complete */
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Main(): Waited and joined with %d threads. Final value of count = "
         "%d. Done. \n",
         NUM_THREADS, count);

  /* Clean up and exit */
  pthread_attr_destroy(&attr);
  pthread_mutex_destroy(&countMutex);
  pthread_cond_destroy(&countThresholdCv);
  pthread_exit(NULL);
}
