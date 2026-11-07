/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    int c, ws;

    ws = 0;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\n':
        case '\t':
        case ' ':
            ++ws;
        default:
            break;
        }
    }
    printf("\nws: '%d'\n", ws);
}
