/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

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

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    unsigned int mask = (((0xFFFFFFFF << p) >> ((sizeof(unsigned int) * 8) - n)) << ((sizeof(unsigned int) * 8) - p - n));

    printf("\nmask:\t");
    printBinary(mask);

    printf("\ninvert:\t");
    printBinary(x ^ mask);

    return x ^ mask;
}

int main(int argc, char **argv)
{
    unsigned int x = 0x0F0F0F0F;
    unsigned int p = 5;
    unsigned int n = 10;

    printf("\np:\t%d", p);
    printf("\nn:\t%d", n);
    printf("\nx:\t");
    printBinary(x);
    invert(x, p, n);
    printf("\n");

    return 0;
}
