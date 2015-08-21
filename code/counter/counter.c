/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_CHILDREN 5

void perror_exit(char *s)
{
  perror(s);  
  exit(-1);
}

void *check_malloc(int size)
{
  void *p = malloc(size);
  if (p == NULL) {
      perror_exit("malloc failed");
  }
  return p;
}

typedef struct {
  int counter;
} Shared;

Shared *make_shared(int end)
{
  Shared *shared = check_malloc(sizeof(Shared));
  shared->counter = 0;
  return shared;
}

pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
  int ret;
  pthread_t thread;

  ret = pthread_create(&thread, NULL, entry, (void *) shared);
  if (ret != 0) {
      perror_exit("pthread_create failed");
  }
  return thread;
}

void join_thread(pthread_t thread)
{
  int ret = pthread_join(thread, NULL);
  if (ret == -1) {
      perror_exit("pthread_join failed");
  }
}

void child_code(Shared *shared)
{
  printf("counter = %d\n", shared->counter);
  shared->counter++;
}

void *entry(void *arg)
{
  Shared *shared = (Shared *) arg;
  child_code(shared);
  pthread_exit(NULL);
}

int main()
{
  int i;
  pthread_t child[NUM_CHILDREN];

  Shared *shared = make_shared(1000000);

  for (i=0; i<NUM_CHILDREN; i++) {
    child[i] = make_thread(entry, shared);
  }

  for (i=0; i<NUM_CHILDREN; i++) {
    join_thread(child[i]);
  }

  return 0;
}
