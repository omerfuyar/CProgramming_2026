/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C com- ments do not nest.
*/

#include <stdio.h>

#define BUFFER_LEN (4 * 1024)
#define ReturnIfIncrementOverflow(variable, limit) \
    do                                             \
    {                                              \
        (variable)++;                              \
        if ((variable) > (limit))                  \
        {                                          \
            return -1;                             \
        }                                          \
    } while (0)

int preprocess(const char *input, int inputLen, char *buffer, int bufferLen);

int main(int argc, char **argv)
{
    char inBuffer[BUFFER_LEN];
    char outBuffer[BUFFER_LEN];

    int inLen = (int)fread(inBuffer, sizeof(char), BUFFER_LEN, stdin);
    int outLen = preprocess(inBuffer, inLen, outBuffer, BUFFER_LEN);

    if (outLen <= 0)
    {
        printf("an error occurred processing code, input may be too large\n");
        return 1;
    }

    fwrite(outBuffer, sizeof(char), outLen, stdout);

    return 0;
}

int preprocess(const char *input, int inputLen, char *buffer, int bufferLen)
{
    int readHead = 0;
    int writeHead = 0;

    while (readHead < inputLen)
    {
        if (input[readHead] == '/')
        {
            ReturnIfIncrementOverflow(readHead, inputLen);

            if (input[readHead] == '/')
            {
                do
                {
                    ReturnIfIncrementOverflow(readHead, inputLen);
                } while (input[readHead] != '\n');
            }
            else if (input[readHead] == '*')
            {
                do
                {
                    do
                    {
                        ReturnIfIncrementOverflow(readHead, inputLen);
                    } while (input[readHead] != '*');

                    ReturnIfIncrementOverflow(readHead, inputLen);
                } while (input[readHead] != '/');

                ReturnIfIncrementOverflow(readHead, inputLen);
            }
        }
        else if (input[readHead] == '"')
        {
            do
            {
                ReturnIfIncrementOverflow(readHead, inputLen);
            } while (input[readHead] != '"');

            ReturnIfIncrementOverflow(readHead, inputLen);
        }
        else
        {
            buffer[writeHead] = input[readHead];

            ReturnIfIncrementOverflow(writeHead, bufferLen);
            ReturnIfIncrementOverflow(readHead, inputLen);
        }
    }

    return writeHead;
}
