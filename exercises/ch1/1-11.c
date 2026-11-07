/*
Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
*/

// putting multiple white space one after another
// different type of white spaces
// putting white space at the start and end
// testing edge cases like buffer overflows or empty inputs

#include <stdio.h>

int main(int argc, char **argv)
{
    int c, ww, wc;

    ww = 0;
    wc = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
        case '\n':
        case '\t':
            ww = 0;
            break;
        default:
            if (ww == 1)
            {
                break;
            }
            ww = 1;
            wc++;
            break;
        }
    }

    printf("word count: '%d'", wc);
    return 0;
}
