/*
ex 1-2. Experiment  to find out what happens when printf’s argument string contains \c, where c is some character not listed above.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("'\\'|'\n'|'\c'");
    return 0;
}
