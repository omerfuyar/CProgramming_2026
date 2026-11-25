/*
exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the right most n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{

    return x;
}

void printBinary(unsigned int number)
{
    for (int i = (sizeof(number) * 8) - 1; i >= 0; i--)
    {
        printf("%u", (number >> (unsigned int)i) & 1U);

        if (i % 8 == 0)
        {
            printf(" ");
        }
    }
}

int main(int argc, char **argv)
{
    unsigned int x = 0;
    unsigned int p = 0;
    unsigned int n = 0;
    unsigned int y = 0;

    printf("\nx:\t");
    printBinary(x);
    printf("\np:\t");
    printBinary(p);
    printf("\nn:\t");
    printBinary(n);
    printf("\ny:\t");
    printBinary(y);
    printf("\nsetbit:\t");
    printBinary(setbits(x, p, n, y));
    printf("\n");

    return 0;
}
