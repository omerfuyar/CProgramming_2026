/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.
*/

#include <stdio.h>

#define MAX_LINE 1000 /* maximum input line length */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAX_LINE];    /* current input line */
    char longest[MAX_LINE]; /* longest line saved here */

    max = 0;
    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* there was a line */
        printf("longest line length is %d: '%s'", max, longest);

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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
