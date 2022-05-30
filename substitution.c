#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be
case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program. */

int main(int argc, string argv[])
{

    string key = (argv[1]);

    /* If your program is executed without any command-line arguments or with more than one command-line argument, your program
    should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error)
    immediately. */

    if (argc != 2)
    {
        printf("usage error one key argument: ./substitution key\n");
        return 1;
    }

    /* If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character,
    or not containing each letter exactly once), your program should print an error message of your choice (with printf)
    and return from main a value of 1 immediately. */

    // Here we check about length (26 characters)
    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("usage error length: ./substitution key\n");
        return 1;
    }

// Here we check about alphabetic characters

    for (int i = 0; i < length; i++)
    {
        char c = key[i];
        if (isalpha(c) == 0)
        {
            printf("usage error alphabetical: ./substitution key\n");
            return 1;
        }
    }

// Here we check against repeated characters

    int tracker[26] = {0};

    int d = 0;

    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < length; j++)
        {

            int c = tolower(key[j]) - 97;

            if (c == d)
            {
                tracker[i] = tracker[i] + 1;
            }

        }

        d++;
        if (tracker[i] != 1)
        {
            printf("usage error duplicate: ./substitution key\n");
            return 1;
        }
    }

//Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
    printf("plaintext: ");
    string plaintext = get_string("");

    int plaintextlength = strlen(plaintext);
    int ciphertext[plaintextlength];
    for (int i = 0; i < plaintextlength; i++)
    {
        if (plaintext[i] >= 97 && plaintext[i] <= 122) //lowercase
        {
            int value = plaintext[i] - 97;

            ciphertext[i] = tolower(key[value]);
        }

        else if (plaintext[i] >= 65 && plaintext[i] <= 90) //uppercase
        {
            int value = plaintext[i] - 65;

            ciphertext[i] = toupper(key[value]);

        }

        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: ");
    for (int i = 0; i < plaintextlength; i++)
    {
        printf("%c", ciphertext[i]);
    }

    printf("\n");

}