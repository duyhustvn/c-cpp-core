// Reference: https://hpc-tutorials.llnl.gov/posix/example_using_mutexes/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <bits/pthreadtypes.h>

typedef struct {
  double *a;
  double *b;
  double sum;
  int veclen;
} DOTDATA;

#define NUM_THREADS 4
#define VEC_LEN 100

DOTDATA dotstr;
pthread_t callThreads[NUM_THREADS];
pthread_mutex_t mutexSum;

void *dotprod(void *arg) {
  long offset = (long)arg;
  int len = dotstr.veclen;
  int start = offset * len;
  int end = start + len;
  double *x = dotstr.a;
  double *y = dotstr.b;

  double mySum = 0;
  for (int i = start; i < end; i++) {
    mySum += (x[i] * y[i]);
  }

  /* Lock a mutex pior to updating the value in the shared
   * structure, and unlock it upon updating
   */

  printf("Thread %ld requires lock\n", offset);
  pthread_mutex_lock(&mutexSum);
  printf("Thread %ld acquires lock\n", offset);
  printf("Thread %ld writes to sum\n", offset);
  dotstr.sum += mySum;
  printf("Thread %ld unlock\n", offset);
  pthread_mutex_unlock(&mutexSum);

  pthread_exit((void *)0);
}

int main(int argc, char *argv[]) {
  double *a = (double *)malloc(NUM_THREADS * VEC_LEN * sizeof(double));
  double *b = (double *)malloc(NUM_THREADS * VEC_LEN * sizeof(double));

  for (long i = 0; i < VEC_LEN * NUM_THREADS; i++) {
    a[i] = 1.0;
    b[i] = a[i];
  }

  dotstr.veclen = VEC_LEN;
  dotstr.a = a;
  dotstr.b = b;
  dotstr.sum = 0;

  /* https://hpc-tutorials.llnl.gov/posix/man/pthread_mutex_init.txt
  **
       The pthread_mutex_init() function shall initialize the mutex referenced
       by mutex with attributes specified  by  attr.  If  attr  is  NULL,  the
       default  mutex  attributes  are  used;  the effect shall be the same as
       passing the address of a default mutex attributes object. Upon success-
       ful  initialization,  the  state  of  the mutex becomes initialized and
       unlocked.

       Only mutex itself may be  used  for  performing  synchronization.   The
       result    of    referring    to   copies   of   mutex   in   calls   to
       pthread_mutex_lock(), pthread_mutex_trylock(),  pthread_mutex_unlock(),
       and pthread_mutex_destroy() is undefined.

       Attempting  to initialize an already initialized mutex results in unde-
       fined behavior.

       In cases where default mutex  attributes  are  appropriate,  the  macro
       PTHREAD_MUTEX_INITIALIZER  can  be  used to initialize mutexes that are
       statically allocated. The effect shall be equivalent  to  dynamic  ini-
       tialization by a call to pthread_mutex_init() with parameter attr spec-
       ified as NULL, except that no error checks are performed.
  */
  pthread_mutex_init(&mutexSum, NULL);

  /* Create threads to perform the dot product */
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for (long i = 0; i < NUM_THREADS; i++) {
    /* Each thread works on different set of data
     * The offset is specified by i. The size of the data for each thred is
     * indicated by VEC_LEN
     * */
    pthread_create(&callThreads[i], &attr, dotprod, (void *)i);
  }

  pthread_attr_destroy(&attr);

  void *status;
  /* Wait on other threads */
  for (long i = 0; i < NUM_THREADS; i++) {
    pthread_join(callThreads[i], &status);
  }

  /* After joining, print out the results and cleanup */
  printf("Sum = %f\n", dotstr.sum);

  free(a);
  free(b);

  pthread_mutex_destroy(&mutexSum);
  pthread_exit(NULL);
}
