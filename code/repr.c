/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>


void print_float() {
    union {
	float f;
	unsigned int u;
    } p;

    p.f = -13.0;
    unsigned int sign = (p.u >> 31) & 1;
    unsigned int exp = (p.u >> 23) & 0xff;

    unsigned int coef_mask = (1 << 23) - 1;
    unsigned int coef = p.u & coef_mask;

    printf("%d\n", sign);
    printf("%d\n", exp);
    printf("%x\n", coef);
}


void print_float2() {
    union {
	float f;
	struct {
	    unsigned int sign:1;
	    unsigned int exp:8;
	    unsigned int coef:23;
	} u;
    } p;

    p.f = -13.0;

    printf("%d\n", p.u.sign);
    printf("%d\n", p.u.exp);
    printf("%x\n", p.u.coef);
}


int main()
{
    int x;

    x = 12 & 10;
    printf("%d\n", x);

    x = 12 | 10;
    printf("%d\n", x);

    x = 12 ^ 10;
    printf("%d\n", x);

    x = (12 ^ -1) + 1;
    printf("%d\n", x);

    print_float();
    print_float2();
}

