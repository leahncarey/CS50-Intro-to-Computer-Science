#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Initialize variable
    long cc;
    int cc1,cc2,cc3,cc4,cc5,cc6,cc7,cc8;
    int cc9,cc10,cc11,cc12,cc13,cc14,cc15,cc16;
    int sum1,sum2,sum3;

    //Prompt user for credit card input until a positive number is entered
    do
    {
        cc = get_long("Please Enter Your Credit Card Number: \n");
    }
    while (cc < 0);

    //Luhn's Algorithm, part 1 (Get every second-to-last place digit)
    //Luhn's Algorithm, part 2 adds the *2 factor
    cc1 = ((cc % 100)/10)*2;
    cc2 = ((cc % 10000)/1000)*2;
    cc3 = ((cc % 1000000)/100000)*2;
    cc4 = ((cc % 100000000)/10000000)*2;
    cc5 = ((cc % 10000000000)/1000000000)*2;
    cc6 = ((cc % 1000000000000)/100000000000)*2;
    cc7 = ((cc % 100000000000000)/10000000000000)*2;
    cc8 = ((cc % 10000000000000000)/1000000000000000)*2;

    //Luhn's algorithm part 3, add the ones place and tens place for cc1-cc8
    cc1 = (cc1 % 10) + ((cc1 % 100)/10);
    cc2 = (cc2 % 10) + ((cc2 % 100)/10);
    cc3 = (cc3 % 10) + ((cc3 % 100)/10);
    cc4 = (cc4 % 10) + ((cc4 % 100)/10);
    cc5 = (cc5 % 10) + ((cc5 % 100)/10);
    cc6 = (cc6 % 10) + ((cc6 % 100)/10);
    cc7 = (cc7 % 10) + ((cc7 % 100)/10);
    cc8 = (cc8 % 10) + ((cc8 % 100)/10);

    //Luhn's algorithm part 4 add the updated cc1-cc8 to the untouched numbers
    //First we will just calculate the untouched numbers cc9-cc15
    cc9 = (cc % 10);
    cc10 = ((cc % 1000)/100);
    cc11 = ((cc % 100000)/10000);
    cc12 = ((cc % 10000000)/1000000);
    cc13 = ((cc % 1000000000)/100000000);
    cc14 = ((cc % 100000000000)/10000000000);
    cc15 = ((cc % 10000000000000)/1000000000000);
    cc16 = ((cc % 1000000000000000)/100000000000000);

    sum1 = cc1 + cc2 + cc3 + cc4 + cc5 + cc6 + cc7 + cc8;
    sum2 = cc9 + cc10 + cc11 + cc12 + cc13 + cc14 + cc15 + cc16;
    sum3 = sum1 + sum2;

    //Luhn's algorithm, final step: Check if the last digit of sum3 is 0. 0 means valid.

    if ((sum3 % 10)!=0)
    {
        printf("INVALID\n");
        return 0;
    }

    long visa = cc;
    long mastercard = cc;
    long amex = cc;

    //Get credit card length
    int length = 0;

    while (cc > 0)
    {
        cc = cc/10;
        length++;
    }

    //Get to first digit of visa
    while (visa >= 10)
    {
        visa=visa/10;
    }


    //Get to first two digits of mastercard (divide by 14 zeroes)
    while (mastercard >= 100000000000000)
    {
        mastercard=mastercard/100000000000000;
    }

    //Get to first two digits of amex (divide by 13 zeroes);
    while(amex >= 10000000000000)
    {
        amex=amex/10000000000000;
    }

    if (length == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
    }

    else if (visa == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }

    else if (length == 16 && (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard ==55))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }


}