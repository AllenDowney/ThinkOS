/******************************************************************
 *                CACHE project                                   *
 *                                                                *
 * Using this program, on as many different kinds of computers as *
 * possible, investigate these cache parameters:                  *
 *      -- total cache size                                       *
 *      -- cache width                                            *
 *      -- cache replacement policy                               *
 ******************************************************************/

/* I got this program from Brian Harvey, who teaches CS61C at
   Berkeley.  He didn't put a copyright on it, but he should
   at least get credit for it.  Thanks, Brian! */

#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>

#define CACHE_MIN (32*1024) /* smallest cache */
#define CACHE_MAX (32*1024*1024) /* largest cache */
#define SAMPLE 10 /* to get a larger time sample */

int x[CACHE_MAX]; /* array going to stride through */
long clk_tck;
 
double get_seconds() { /* routine to read time */
    struct tms rusage;
    times(&rusage); /* UNIX utility: time in clock ticks */
    return (double) (rusage.tms_utime)/clk_tck;
}

int main() {
    int register i, index, stride, limit, temp;
    int steps, tsteps, csize;
    double sec0, sec; /* timing variables */

    clk_tck = sysconf(_SC_CLK_TCK);
 
    for (csize=CACHE_MIN; csize <= CACHE_MAX; csize=csize*2) 
	for (stride=1; stride <= csize/2; stride=stride*2) {
	    sec = 0; /* initialize timer */
	    limit = csize-stride+1; /* cache size this loop */
     
	    steps = 0;
	    do { /* repeat until collect 1 second */
		sec0 = get_seconds(); /* start timer */
		for (i=SAMPLE*stride;i!=0;i=i-1) /* larger sample */
		    for (index=0; index < limit; index=index+stride) 
		        x[index] = x[index] + 1; /* cache access */
		steps = steps + 1; /* count while loop iterations */
		sec = sec + (get_seconds() - sec0);/* end timer */
	    } while (sec < 1.0); /* until collect 1 second */
     
	    /* Repeat empty loop to loop subtract overhead */
	    tsteps = 0; /* used to match no. while iterations */
	    do { /* repeat until same no. iterations as above */
		sec0 = get_seconds(); /* start timer */
		for (i=SAMPLE*stride;i!=0;i=i-1) /* larger sample */
		    for (index=0; index < limit; index=index+stride) 
		        temp = temp + index; /* dummy code */
		tsteps = tsteps + 1; /* count while iterations */
		sec = sec - (get_seconds() - sec0);/* - overhead */
	    } while (tsteps<steps); /* until = no. iterations */
     
	    printf("Size: %7ld Stride: %7ld read+write: %4.4lf ns\n",
	       csize*sizeof(int), stride*sizeof(int),
	       (double) sec*1e9/(steps*SAMPLE*stride*((limit-1)/stride+1)));
	}; /* end of both outer for loops */
}

