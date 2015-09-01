/* Example code for Think OS.

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"
#include "mysem.h"

Semaphore *make_semaphore(int value)
{
  Semaphore *semaphore = check_malloc(sizeof(Semaphore));
  // initialize the fields here
  return semaphore;
}

void semaphore_wait(Semaphore *semaphore)
{
  // put your implementation here
}

void semaphore_signal(Semaphore *semaphore)
{
  // put your implementation here
}
