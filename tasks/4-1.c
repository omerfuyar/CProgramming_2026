/*
exercise 4-1:
Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s,
or -1 if there is none.
Think about how to fix or modify the function to meet ex4-1.
Ex) s[] = “abcdedfabcde”, t[] =“abc” , rightmost index = 7
*/

#include <stdio.h>

#define STR_SOURCE "abcdedfabcde"
#define STR_PATTERN "abc"

int strLength(const char *str)
{
    int index = 0;

    while (str[index] != '\0')
    {
        index++;
    }

    return index;
}

int strCompare(const char *strA, const char *strB, int range)
{
    int index = 0;
    while (index < range && strA[index] != '\0' && strB[index] != '\0')
    {
        if (strA[index] != strB[index])
        {
            return (strA[index] - strB[index]);
        }

        index++;
    }

    return 0;
}

int strrindex(const char *source, const char *pattern)
{
    int sourceLength = strLength(source);
    int patternLength = strLength(pattern);

    if (patternLength > sourceLength)
    {
        return -1;
    }

    int index = sourceLength - patternLength;
    while (index >= 0)
    {
        if (strCompare(source + index, pattern, patternLength) == 0)
        {
            return index;
        }

        index--;
    }

    return -1;
}

int main()
{
    printf("right most index of '%s' inside '%s' is '%d'\n", STR_PATTERN, STR_SOURCE, strrindex(STR_SOURCE, STR_PATTERN));
    return 0;
}
