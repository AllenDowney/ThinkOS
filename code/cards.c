/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
int main()
{
  int val = 0;
  char card_name[] = "8";

  if (card_name[0] == 'K') {
    val = 10;
  } else if (card_name[0] == 'K') {
    val = 10;
  } else if (card_name[0] == 'Q') {
    val = 10;
  } else if (card_name[0] == 'J') {
    val = 10;
  } else if (card_name[0] == 'A') {
    val = 11;
  } else {
    val = atoi(card_name);
  }

  printf("%d\n", val);
}
