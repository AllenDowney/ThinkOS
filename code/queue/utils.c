/* Example code for Think OS.

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"

// UTILITY CODE

void perror_exit(char *s)
{
  perror(s);  
  exit(-1);
}

void *check_malloc(int size)
{
  void *p = malloc(size);
  if (p == NULL) perror_exit("malloc failed");
  return p;
}

// MUTEX WRAPPER

Mutex *make_mutex()
{
  Mutex *mutex = check_malloc(sizeof(Mutex));
  int n = pthread_mutex_init(mutex, NULL);
  if (n != 0) perror_exit("make_lock failed"); 
  return mutex;
}

void mutex_lock(Mutex *mutex)
{
  int n = pthread_mutex_lock(mutex);
  if (n != 0) perror_exit("lock failed");
}

void mutex_unlock(Mutex *mutex)
{
  int n = pthread_mutex_unlock(mutex);
  if (n != 0) perror_exit("unlock failed");
}

// COND WRAPPER

Cond *make_cond()
{
  Cond *cond = check_malloc(sizeof(Cond)); 
  int n = pthread_cond_init(cond, NULL);
  if (n != 0) perror_exit("make_cond failed");
 
  return cond;
}

void cond_wait(Cond *cond, Mutex *mutex)
{
  int n = pthread_cond_wait(cond, mutex);
  if (n != 0) perror_exit("cond_wait failed");
}

void cond_signal(Cond *cond)
{
  int n = pthread_cond_signal(cond);
  if (n != 0) perror_exit("cond_signal failed");
}

