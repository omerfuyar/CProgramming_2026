/*
Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define MAX_LINE 256 /* maximum input line length */
#define COLUMN_LEN 8

int mygetline(char line[], int maxline);
int takeBreakXd(const char *str, int len);

/* print the longest input line */
int main()
{
    int len;             /* current line length */
    char line[MAX_LINE]; /* current input line */

    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        int readHead = 0;
        int breakLen = takeBreakXd(line, len);
        while (breakLen > 0)
        {
            printf("'%.*s'\n", breakLen, line + readHead);
            readHead += breakLen;
            breakLen = takeBreakXd(line + readHead, len - readHead);
        }
    }

    return 0;
}

/* getline: read a line into line, return length */
int mygetline(char line[], int maxline)
{
    int c = EOF;
    int i = 0;

    if (maxline <= 0)
        return 0;

    while (i < maxline - 1 &&
           (c = getchar()) != EOF &&
           c != '\n')
    {
        line[i++] = (char)c;
    }

    line[i] = '\0';
    return i;
}

int takeBreakXd(const char *str, int len)
{
    for (int i = ((COLUMN_LEN - 1) > len - 1 ? len - 1 : (COLUMN_LEN - 1)); i >= 0; i--)
    {
        switch (str[i])
        {
        case ' ':
        case '\n':
        case '\t':
            break;

        default:
            return i + 1;
        }
    }

    return 0;
}
