/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should ʼn be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define MAX_LINE 256 /* maximum input line length */
#define TAB_COLUMN 4

int mygetline(char line[], int maxline);
void detab(char *buf, const char *str, int len);

/* print the longest input line */
int main()
{
    int len;                  /* current line length */
    char line[MAX_LINE];      /* current input line */
    char lineDetab[MAX_LINE]; /* current input line */
    int selectedLineCount = 0;

    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        detab(lineDetab, line, len);
        printf("detab : '%s'\n", lineDetab);
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

void detab(char *buf, const char *str, int len)
{
    int readHead = 0;
    int writeHead = 0;

    while (writeHead < len)
    {
        if (str[readHead] == '\t')
        {
            for (int i = 0; i < writeHead % TAB_COLUMN; i++)
            {
                buf[writeHead] = ' ';
                writeHead++;
            }
            readHead++;
        }
        else
        {
            buf[writeHead] = str[readHead];
            readHead++;
            writeHead++;
        }
    }
}
