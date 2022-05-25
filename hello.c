#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // First, gets the user's name and then greets the user
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}