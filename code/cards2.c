/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
int main()
{
  int val = 0;
  char card_name[] = "Q";

  switch (card_name[0]) {
  case 'K':
  case 'Q':
  case 'J':
    val = 10;
    break;
  case 'A':
    val = 11;
    break;
  default:
    val = atoi(card_name);
  }

  printf("%d\n", val);
}
