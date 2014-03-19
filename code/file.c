/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
int main()
{
    FILE *fp = fopen("/home/downey/file.txt", "w");
    fputc('b', fp);
    fclose(fp);

    fopen("/home/downey/file.txt", "r");
    char c = fgetc(fp);
    printf("%c\n", c);
}
