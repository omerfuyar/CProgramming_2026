/*
Ex 2-5. Write the function any(s1,s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no character from s2. (The standard lib. Function strpbrk does the sam job but returns a pointer to the location)
*/

#include <stdio.h>

int charInStr(int c, const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }

    return -1;
}

int any(const char *str, const char *chars)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (charInStr(str[i], chars) != -1)
        {
            return i;
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    const char *str = "I am alive";
    const char *chars = "la";
    printf("first occurrence of any character '%s' in string '%s' is '%d'\n", chars, str, any(str, chars));

    return 0;
}
