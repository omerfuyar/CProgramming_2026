/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAX_LINE 256 /* maximum input line length */
#define MAX_STR 32

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
int realLen(char *str, int len);

/* print the longest input line */
int main()
{
    int len;                               /* current line length */
    char line[MAX_LINE];                   /* current input line */
    char selectedLines[MAX_STR][MAX_LINE]; /* lines longer than  LEN_THRESHOLD*/
    int selectedLineCount = 0;

    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        int realLength = realLen(line, len);
        if (realLength > 0)
        {
            copy(selectedLines[selectedLineCount], line);
            selectedLines[selectedLineCount][realLength] = '\0';
            selectedLineCount++;
        }
    }

    printf("\nend-stripped non-empty lines:\n");
    for (int i = 0; i < selectedLineCount; i++)
    {
        printf("'%s'", selectedLines[i]);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int realLen(char *str, int len)
{
    for (int i = len - 1; i >= 0; i--)
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
