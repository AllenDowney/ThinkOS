#include <stdio.h>
#include <stdlib.h>

int seconds;

int main (int argc, char *argv[])
{
  int i = 0;

  if (argc == 2) {
    seconds = atoi (argv[1]);
  } else {
    printf ("Usage: sleep [duration in seconds]\n");
    exit (-1);
  }

  printf ("Address of seconds is 0x%.8x\n", &seconds);
  printf ("Value of seconds is %d\n", seconds);

  sleep (seconds);

  printf ("Address of seconds is 0x%.8x\n", &seconds);
  printf ("Value of seconds is %d\n", seconds);


}
