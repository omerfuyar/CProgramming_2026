/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>

#define CHAR_COUNT 10

int main(int argc, char **argv)
{
    int c, wl;

    wl = 0;
    int wls[CHAR_COUNT] = {0};

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
        case '\n':
        case '\t':
            if (wl > 0 && wl < CHAR_COUNT)
            {
                wls[wl - 1]++;
            }
            wl = 0;
            break;
        default:
            wl++;
            break;
        }
    }

    printf("Word length histogram, range 0-%d:\n", CHAR_COUNT);
    for (int i = 0; i < CHAR_COUNT; i++)
    {
        printf("[%d]\t", i + 1);
        for (int j = 0; j < wls[i]; j++)
        {
            printf("█");
        }
        printf("\n");
    }
    return 0;
}
