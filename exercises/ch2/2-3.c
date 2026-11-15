/*
write the function htoi(s), which converts a string of hexa-decimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, an through f, and A through F.
*/

#include <stdio.h>

int hextodec(char character)
{
    switch (character)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'a':
    case 'A':
        return 10;
    case 'b':
    case 'B':
        return 11;
    case 'c':
    case 'C':
        return 12;
    case 'd':
    case 'D':
        return 13;
    case 'e':
    case 'E':
        return 14;
    case 'f':
    case 'F':
        return 15;
    default:
        return -1;
    }
}

int htoi(const char *str)
{
    int strLen = 0;
    while (str[strLen] != '\0')
    {
        strLen++;
    }

    if (strLen == 0)
    {
        return 0;
    }

    int readStop = 0;

    if (strLen > 1 && (str[1] == 'x' || str[1] == 'X'))
    {
        if (str[0] != '0' || strLen < 3)
        {
            return 0;
        }

        readStop = 2;
    }

    int result = 0;
    int readHead = strLen - 1;

    while (readHead >= readStop)
    {
        int digitValue = strLen - readHead - 1;

        int step = 1;

        for (int i = 0; i < digitValue; i++)
        {
            step *= 16;
        }

        int hexValue = hextodec(str[readHead]);
        if (hexValue == -1)
        {
            return 0;
        }

        result += step * hexValue;

        readHead--;
    }

    return result;
}

int main(int argc, char **argv)
{
    const char *hexStr = "0xdead";
    printf("decimal value of '%s' is : '%d'\n", hexStr, htoi(hexStr));

    return 0;
}
