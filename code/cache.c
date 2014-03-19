/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

This is a modified version of a program I used in cs61c
at U.C. Berkeley.  I don't know the author.

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>

#define SIZE_MIN (1024)      /* smallest array size # elements */
#define SIZE_MAX (32*1024*1024) /* largest array size */
#define STRIDE_MIN 2           /* smallest stride # elements */
#define STRIDE_MAX 128         /* largest stride # elements */

int array[SIZE_MAX];


// Returns CPU time in seconds.
double get_seconds(){
    struct timespec ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}


// Measures CPU time per read+write and prints results.
// size: array size
// stride: stride length of the access pattern
void benchmark(long size, int stride) {
    long limit;
    int i, index, temp;
    int iters, iters2;
    double sec0, sec; /* timing variables */

    sec = 0; /* initialize timer */
    limit = size-stride+1; /* cache size this loop */
     
    iters = 0;
    do { /* repeat until collect 1 second */
	sec0 = get_seconds(); /* start timer */

	for (index = 0; index < limit; index += stride) 
	    array[index] = array[index] + 1; /* cache access */
	
	iters = iters + 1; /* count while loop iterations */
	sec = sec + (get_seconds() - sec0);/* end timer */
	
    } while (sec < 0.1); /* run at least 0.1 seconds */
    
    /* Repeat empty loop to loop subtract overhead */
    iters2 = 0; /* used to match no. while iterations */
    do { /* repeat until same no. iterations as above */
	sec0 = get_seconds(); /* start timer */
	
	for (index = 0; index < limit; index += stride) 
	    temp = temp + index; /* dummy code */
	
	iters2 = iters2 + 1; /* count while iterations */
	sec = sec - (get_seconds() - sec0);/* - overhead */

    } while (iters2 < iters); /* until = no. iterations */
    
    printf("Size: %7ld Stride: %7ld read+write: %4.4lf ns\n",
	   size * sizeof(int), stride * sizeof(int),
	   sec * 1e9 / iters / limit * stride);
}


int main() {
    long size;
    int stride;

    for (size=SIZE_MIN; size <= SIZE_MAX; size=size*2) {
	for (stride=STRIDE_MIN; stride <= STRIDE_MAX; stride=stride*2) {
	    benchmark(size, stride);
	}
    }
}

