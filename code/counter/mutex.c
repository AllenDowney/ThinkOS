/* Example code for Software Systems at Olin College.

Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdlib.h>
#include <pthread.h>
#include "mutex.h"

Mutex *make_mutex()
{
    Mutex *mutex = (Mutex *) malloc(sizeof(Mutex));
    pthread_mutex_init(mutex->mutex, NULL);
    return mutex;
}

void mutex_lock(Mutex *mutex)
{
    pthread_mutex_lock(mutex->mutex);
}

void mutex_unlock(Mutex *mutex)
{
    pthread_mutex_unlock(mutex->mutex);
}
