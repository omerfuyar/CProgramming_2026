/*
Exercise 1-12. Write a program that prints its input one word per line.
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
        case '\t':
            ws = 0;
            break;
        case '\n':
            putchar('\n');
            putchar('\n');
            break;
        default:
            if (ws == 1)
            {
                putchar(c);
                break;
            }
            ws = 1;
            putchar('\n');
            putchar(c);
            break;
        }
    }

    return 0;
}
