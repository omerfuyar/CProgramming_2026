/*
Ex 2-4. Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
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

void squeeze(char *str, const char *chars)
{
    int writeHead = 0;
    int readHead = 0;

    while (str[readHead] != '\0')
    {
        if (charInStr(str[readHead], chars) == -1)
        {
            str[writeHead] = str[readHead];
            writeHead++;
        }

        readHead++;
    }

    str[writeHead] = '\0';
}

int main(int argc, char **argv)
{
    char buffer[64] = "I am alive";
    printf("original : '%s'\n", buffer);
    squeeze(buffer, "ve");
    printf("squeezed : '%s'\n", buffer);

    return 0;
}
