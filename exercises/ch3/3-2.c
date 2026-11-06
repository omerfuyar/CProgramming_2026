/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for other direction as well, converting escape sequences into the real characters.

Suppose that  input t[] = “Hello\tworld\nThis is a test.”
•write escape(s,t) that copies characters from t to s, but converts newline(\n) and tab(\t) characters into their respective escape sequences( \\n, \\t)
•and unescaped(s,t) that convert escape sequences(\\n, \\t) back into their corresponding special characters(\n,\t)
*/

#include <stdio.h>

#define STR_BUFFER_SIZE 256
#define STR_ESCAPE "Hello\tworld\nThis is a test."
#define STR_UNESCAPE "Hello\\tworld\\nThis is a test."

void escaped(char *buffer, int bufferSize, const char *source)
{
    int readIdx = 0;
    int writeIdx = 0;

    while (writeIdx < bufferSize - 1)
    {
        char currentChar = source[readIdx];

        readIdx++;

        switch (currentChar)
        {
        case '\0':
            goto out;
        case '\t':
        case '\n':
        case '\r':
        case '\f':
            buffer[writeIdx] = '\\';

            if (writeIdx + 1 >= bufferSize - 1)
            {
                goto out;
            }

            writeIdx++;

            switch (currentChar)
            {
            case '\t':
                buffer[writeIdx] = 't';
                break;
            case '\n':
                buffer[writeIdx] = 'n';
                break;
            case '\r':
                buffer[writeIdx] = 'r';
                break;
            case '\f':
                buffer[writeIdx] = 'f';
                break;
            default:
                break;
            }
            break;
        default:
            buffer[writeIdx] = currentChar;
            break;
        }

        writeIdx++;
    }

out:
    buffer[writeIdx] = '\0';
}

void unescaped(char *buffer, int bufferSize, const char *source)
{
    int readIdx = 0;
    int writeIdx = 0;

    while (writeIdx < bufferSize - 1)
    {
        char currentChar = source[readIdx];
        readIdx++;

        if (currentChar == '\0')
        {
            goto out;
        }
        else if (currentChar == '\\')
        {
            char nextChar = source[readIdx];
            readIdx++;

            switch (nextChar)
            {
            case 't':
                buffer[writeIdx] = '\t';
                break;
            case 'n':
                buffer[writeIdx] = '\n';
                break;
            case 'r':
                buffer[writeIdx] = '\r';
                break;
            case 'f':
                buffer[writeIdx] = '\f';
                break;
            default:
                break;
            }
        }
        else
        {
            buffer[writeIdx] = currentChar;
        }

        writeIdx++;
    }

out:
    buffer[writeIdx] = '\0';
}

int main()
{
    char buffer[STR_BUFFER_SIZE];

    escaped(buffer, sizeof(buffer), STR_ESCAPE);
    printf("escaped : '%s' -> '%s'\n\n", STR_ESCAPE, buffer);

    unescaped(buffer, sizeof(buffer), STR_UNESCAPE);
    printf("unescaped : '%s' -> '%s'\n", STR_UNESCAPE, buffer);

    return 0;
}
