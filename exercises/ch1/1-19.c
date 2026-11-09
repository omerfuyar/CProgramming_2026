/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAX_LINE 256 /* maximum input line length */
#define MAX_STR 32

int mygetline(char line[], int maxline);
void reverse(char *buf, const char *str, int len);

/* print the longest input line */
int main()
{
    int len;                     /* current line length */
    char line[MAX_LINE];         /* current input line */
    char lineReversed[MAX_LINE]; /* current input line */
    int selectedLineCount = 0;

    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        reverse(lineReversed, line, len);
        printf("reversed : '%s'\n", lineReversed);
    }

    return 0;
}

/* getline: read a line into line, return length */
int mygetline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 &&
                (c = getchar()) != EOF && c != '\n';
         ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void reverse(char *buf, const char *str, int len)
{
    for (int index = len - 1; index >= 0; index--)
    {
        buf[len - index - 1] = str[index];
    }
}
