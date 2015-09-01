/* Example code for Think OS.

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

typedef struct {
  int value, wakeups;
  Mutex *mutex;
  Cond *cond;
} Semaphore;

Semaphore *make_semaphore(int value);
void semaphore_wait(Semaphore *semaphore);
void semaphore_signal(Semaphore *semaphore);
