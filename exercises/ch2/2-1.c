/*
exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both singed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("char\t\t-> %zu\n", sizeof(char));
    printf("short\t\t-> %zu\n", sizeof(short));
    printf("int\t\t-> %zu\n", sizeof(int));
    printf("long\t\t-> %zu\n", sizeof(long));
    printf("long long\t-> %zu\n", sizeof(long long));
    printf("float\t\t-> %zu\n", sizeof(float));
    printf("double\t\t-> %zu\n", sizeof(double));
    printf("long double\t-> %zu\n", sizeof(long double));

    return 0;
}
