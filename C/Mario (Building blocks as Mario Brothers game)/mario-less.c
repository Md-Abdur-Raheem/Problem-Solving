#include "../Libraries/cs50.h"
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    int space = height - 1; // to count the space before the #

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < space; j++) // to print the space before #
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++) // to print #
        {
            printf("#");
        }
        space--; // to decrease the space in each every line
        printf("\n");
    }
}