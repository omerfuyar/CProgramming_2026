/*
write a program to calculate the equation with polish notation (postfix) instead of infix
Infix notation (1-2) * (4 +5)  is entered as 1 2 – 4 5 + *
*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_CAPACITY 256
#define INPUT_STR "1 2 - 4 5 + *"

int strNextToken(const char *str, int *retLength)
{
    int i = 0;

    if (str[i] == ' ')
    {
        while (str[i] == ' ' && str[i] != '\0')
        {
            i++;
        }

        *retLength = 0;
    }
    else
    {
        while (str[i] != ' ' && str[i] != '\0')
        {
            i++;
        }

        *retLength = i;

        while (str[i] == ' ' && str[i] != '\0')
        {
            i++;
        }
    }

    return i;
}

int strToInt(const char *str, int strLen)
{
    int result = 0;
    int i = strLen - 1;

    while (i >= 0)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("str '%s' not a number\n", str);
            exit(1);
        }

        int digitValue = str[i] - '0';

        for (int j = 0; j < (strLen - i + 1); j++)
        {
            digitValue *= 10;
        }

        result += digitValue;

        i--;
    }

    return result;
}

int strToOpt(const char *str)
{
    switch (*str)
    {
    case '-':
    case '+':
    case '*':
    case '/':
        return *str;
    default:
        printf("invalid operator '%s'\n", str);
        exit(1);
        break;
    }
}

int calculate(const char *str)
{
    int result = 0;

    struct
    {
        int count;
        int data[STACK_CAPACITY];
    } stack = {0};

    int currentTokenLen = 0;
    char *currentToken = str;

    while ()

        return result;
}

int main()
{
    printf("result of '%s' is '%d'", INPUT_STR, calculate(INPUT_STR));
    return 0;
}
