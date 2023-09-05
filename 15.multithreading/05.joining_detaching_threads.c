// Reference: https://hpc-tutorials.llnl.gov/posix/joining_and_detaching/
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *BusyWork(void *t) {
  long tid = (long)t;
  printf("Thread %ld starting...\n", tid);
  char returnValue[100];
  sprintf(returnValue, "return value from thread %ld", tid);
  pthread_exit((void *)returnValue);
}

/*
** Joining is used when yu need to wait for thread's completion and retrieve
** its exit status. It's suitable for coordinating the execution flow among
** threads
**
** Detaching is used when yu don't need to wait for a thread and don't care
** about its exit status. It's suitable for threads that run independently
** and can clean up after themselves
*/
int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  /*
  ** DESCRIPTION
       The  detachstate  attribute controls whether the thread is created in a
       detached state. If the thread is created detached, then use of  the  ID
       of  the  newly created thread by the pthread_detach() or pthread_join()
       function is an error.

       The  pthread_attr_getdetachstate()  and   pthread_attr_setdetachstate()
       functions, respectively, shall get and set the detachstate attribute in
       the attr object.

       For pthread_attr_getdetachstate(), detachstate shall be set  to  either
       PTHREAD_CREATE_DETACHED or PTHREAD_CREATE_JOINABLE.

       For  pthread_attr_setdetachstate(),  the  application shall set detach-
       state to either PTHREAD_CREATE_DETACHED or PTHREAD_CREATE_JOINABLE.

       A value of PTHREAD_CREATE_DETACHED shall cause all threads created with
       attr to be in the detached state, whereas using a value of PTHREAD_CRE-
       ATE_JOINABLE shall cause all threads created with attr  to  be  in  the
       joinable state. The default value of the detachstate attribute shall be
       PTHREAD_CREATE_JOINABLE.
  */
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for (long t = 0; t < NUM_THREADS; t++) {
    printf("Main: creating thread %ld \n", t);
    int rc = pthread_create(&threads[t], &attr, BusyWork, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  /* Free attribute and wait for other threads */
  pthread_attr_destroy(&attr);

  void *status;
  for (long t = 0; t < NUM_THREADS; t++) {
    /*
    ** The  pthread_join()  function  shall  suspend  execution of the calling
       thread until the target thread terminates, unless the target thread has
       already  terminated.  On  return  from a successful pthread_join() call
       with a non-NULL value_ptr argument, the value passed to  pthread_exit()
       by  the terminating thread shall be made available in the location ref-
       erenced by value_ptr. When a pthread_join() returns  successfully,  the
       target thread has been terminated. The results of multiple simultaneous
       calls to pthread_join() specifying the same  target  thread  are  unde-
       fined.  If the thread calling pthread_join() is canceled, then the tar-
       get thread shall not be detached.

       It is unspecified whether a thread that has exited but remains unjoined
       counts against {PTHREAD_THREADS_MAX}.
    */
    int rc = pthread_join(threads[t], &status);
    if (rc) {
      printf("ERROR; return code from pthread_join() is %d\n", rc);
      exit(-1);
    }

    printf("Main: completed join with thread %ld having status of: %s\n", t,
           (char *)status);
  }
  printf("Main: program completed. Exiting.\n");
  pthread_exit(NULL);
}
