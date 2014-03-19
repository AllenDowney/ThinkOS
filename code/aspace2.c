/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void recurse (int n)
{
    int a[4000];
    int x;
    void *q = malloc(128);

    printf ("Address of a is %p\n", &a[0]);
    printf ("Address of x is %p\n", &x);
    printf ("Address of q is %p\n", q);

    if (n > 0) recurse (n-1);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    
    recurse (1);
    return 0;
}
