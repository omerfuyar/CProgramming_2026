/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
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

    printf("\nx:\t");
    printBinary(x);
    printf("\np:\t");
    printBinary(p);
    printf("\nn:\t");
    printBinary(n);
    printf("\ninvert:\t");
    printBinary(invert(x, p, n));
    printf("\n");

    return 0;
}
