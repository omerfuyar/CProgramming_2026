/*
ex 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

int fahrenheitToCelsius(int fahrenheit)
{
    return 5 * (fahrenheit - 32) / 9;
}

int celsiusToFahrenheit(int celsius)
{
    return celsius * 9 / 5 + 32;
}

int main(int argc, char **argv)
{
    int fahrenheit, celsius;
    int lower, upper, step;

    lower = -20; /* lower limit of temperature table */
    upper = 160; /* upper limit */
    step = 20;   /* step size */

    printf("celsius\tfahrenheit\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahrenheit = celsiusToFahrenheit(celsius);
        printf("%d\t\t%d\n", celsius, fahrenheit);
        celsius = celsius + step;
    }
}
