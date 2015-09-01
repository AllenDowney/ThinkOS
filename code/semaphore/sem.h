/* Example code for Think OS

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

typedef sem_t Semaphore;

Semaphore *make_semaphore(int value);
void semaphore_wait(Semaphore *sem);
void semaphore_signal(Semaphore *sem);
