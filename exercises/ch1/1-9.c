/*
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
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
        case ' ':
            if (ws == 1)
            {
                break;
            }
            ws = 1;
            putchar(c);
            break;
        default:
            ws = 0;
            putchar(c);
            break;
        }
    }
}
