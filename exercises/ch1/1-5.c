/*
ex 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degree to 0.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    int fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    printf("fahrenheit\tcelsius\n");
    fahrenheit = upper;
    while (fahrenheit >= lower)
    {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%d\t\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit - step;
    }
}
