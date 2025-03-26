#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    int sc = 0;
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Unable to open the file: %s\n", argv[1]);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == ' ')
            {
                sc++;
            }
        }
        printf("Number of spaces: %d\n", sc);
        fclose(fp);
    }
    return 0;
}
//output

vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ gedit cp.c
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ gcc cp.c
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ ./a.out
Usage: ./a.out <filename>
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ ./a.out cp.c
Number of spaces: 215
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ gedit grep.c
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ gcc grep.c
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ ./a.out 
usage:	./a.out filename word
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ ./a.out  grep.c
usage:	./a.out filename word
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ ./a.out  grep.c include
grep.c: 1 #include <stdio.h>
grep.c: 2 #include <string.h>
grep.c: 3 #include <stdlib.h>
