/* Example code for Think OS.

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

int global = 0;

int times_called()
{
  static int counter = 0;
  printf ("Address of counter is %p\n", &counter);
  counter++;
  return counter;
}

int main ()
{
  int i, x;
  int local = 5;
  void *p = malloc(128);

  printf ("Address of main is %p\n", main);
  printf ("Address of global is %p\n", &global);
  printf ("Address of local is %p\n", &local);
  printf ("Address of p is %p\n", p);
  
  for (i=0; i<3; i++) {
    x = times_called();
    printf("%d\n", x);
  }

  return 0;
}
