/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAX_LINE 256 /* maximum input line length */
#define MAX_STR 32
#define LEN_THRESHOLD 80

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;                               /* current line length */
    char line[MAX_LINE];                   /* current input line */
    char selectedLines[MAX_STR][MAX_LINE]; /* lines longer than  LEN_THRESHOLD*/
    int selectedLineCount = 0;

    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        if (len > LEN_THRESHOLD)
        {
            copy(selectedLines[selectedLineCount], line);
            selectedLineCount++;
        }
    }

    printf("\nlines longer then %d:\n", LEN_THRESHOLD);
    for (int i = 0; i < selectedLineCount; i++)
    {
        printf("%s", selectedLines[i]);
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
