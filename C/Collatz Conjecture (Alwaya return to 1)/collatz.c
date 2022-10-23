#include "../Libraries/cs50.h"
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int number = get_int("Number: ");

    int steps = collatz(number);

    printf("Steps: %i", steps);
}

int step_counter = 0;

int collatz(int n)
{
    // base case
    if (n == 1)
    {
        return step_counter;
    }

    // multiple recursive case
    else if (n % 2 == 0)
    {
        step_counter++;
        collatz(n / 2);
    }
    else if (n % 2 != 0)
    {
        step_counter++;
        collatz((3 * n) + 1);
    }
}