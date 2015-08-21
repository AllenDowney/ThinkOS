/* Example code for Think OS

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <pthread.h>

typedef struct {
  pthread_mutex_t mutex[1];
} Mutex;

Mutex *make_mutex ();
void mutex_lock(Mutex *mutex);
void mutex_unlock(Mutex *mutex);
