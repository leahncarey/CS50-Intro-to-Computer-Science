#include <cs50.h>
#include <stdio.h>

//every time row is increased column initializes back to 0

int main(void)
{
    //scope variable
    int height;

    //Get a positive height from 1-8
    do
    {
        height = get_int("What is the height? ");
    }
    while (height < 1 || height > 8);

    //For each row
    for (int row = 0; row < height; row++)
    {
        //right aligning add spaces before hashes and before line prints at end of the row
        for (int space = 0; space < height - row - 1 ; space++)
        {
            printf(" ");
        }

        //for each column
        for (int column = 0; column < row + 1; column++)
        {

            printf("#");

        }
        //print the two spaces before the left aligned pyramid and new row prints
        printf("  ");

        //print the left aligned pyramid before the new row prints
        for (int column = 0; column < row + 1; column++)
        {
            printf("#");
        }

        //print the new row
        printf("\n");

    }


}