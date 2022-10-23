#include "../Libraries/cs50.h"
#include <stdio.h>

void block(int length); // print block function

int main(void)
{
    int height;
    do // taking height of the block from user
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    int space = height - 1; // to count the space before #

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < space; j++) // to print the space before #
        {
            printf(" ");
        }

        block(i); // call the block function to print 1st set of #

        printf("  "); // to print the space between two sets of block

        block(i); // call the block function to print the 2nd set of #

        space--;      // to decrease the space in each line
        printf("\n"); // to move to a new row
    }
}

// block function to print #
void block(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
}