/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
*/

#include <stdio.h>

#define MAX_LINE 256 /* maximum input line length */
#define TAB_COLUMN 4

int mygetline(char line[], int maxline);
void entab(char *buf, const char *str, int len);

/* print the longest input line */
int main()
{
    int len;                  /* current line length */
    char line[MAX_LINE];      /* current input line */
    char lineEntab[MAX_LINE]; /* current input line */

    while ((len = mygetline(line, MAX_LINE)) > 0)
    {
        entab(lineEntab, line, len);
        printf("detab : '%s'\n", lineEntab);
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

void entab(char *buf, const char *str, int len)
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
