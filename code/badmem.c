/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>

void f1() {
    int i;
    // int array[100];
    float array[100];

    for (i=0; i<100; i++) {
	array[i] = i;
    }
}

void f2() {
    int x = 17;
    int array[10];
    int y = 123;

    printf("%d\n", array[-2]);
    printf("%d\n", array[-1]);
    printf("%d\n", array[10]);
    printf("%d\n", array[11]);
}

void f3() {
    /* Read beyond the bounds of a string */
    float x = 3.141592653;
    char array[] = "allen";

    printf("%c\n", array[-2]);
    printf("%c\n", array[-1]);
}

void f4() {
    char array[] = "Allen Downey";
    float *p = array;

    printf("%f\n", (double) *p);
}

int main()
{
    //    f1();
    //f2();
    //f3();
    f4();
}

