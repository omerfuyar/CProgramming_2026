/*
Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\t':
        case '\\':
        case '\b':
            putchar('\\');
            switch (c)
            {
            case '\t':
                putchar('t');
                break;
            case '\\':
                putchar('\\');
                break;
            case '\b':
                putchar('b');
                break;
            default:
                break;
            }
            break;
        default:
            putchar(c);
            break;
        }
    }
}
