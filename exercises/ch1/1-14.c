/*
Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
*/

#include <stdio.h>

#define CHAR_COUNT 26

int main(int argc, char **argv)
{
    int c, wl;

    wl = 0;
    int wls[CHAR_COUNT] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            wls[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            wls[c - 'A']++;
        }
    }

    printf("Character histogram, range 0-%d:\n", CHAR_COUNT);
    for (int i = 0; i < CHAR_COUNT; i++)
    {
        printf("[%c] %d |", 'A' + i, wls[i]);
        for (int j = 0; j < wls[i]; j++)
        {
            printf("█");
        }
        printf("\n");
    }
    return 0;
}
