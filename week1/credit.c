#include <cs50.h>#include <stdio.h>

int digitcount(long num);

int main(void)
{
    long Creditnumber = get_long("Number: ");
    int doubledigits = 0;
    int notdoubledigit = 0;
    int digitcounts = digitcount(Creditnumber);

    // early break if wrong length of cardnumber
    if (digitcounts != 13 && digitcounts != 15 && digitcounts != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // sum up digits
    int last2digits = 0;
    for (int i = 0; i < digitcounts; i++)
    {
        if (i == digitcounts - 2)
        {
            last2digits += Creditnumber;
        }
        notdoubledigit += Creditnumber % 10;
        Creditnumber /= 10;
        int doubled_digit = (Creditnumber % 10) * 2;
        if (doubled_digit / 10 > 0)
        {
            // first one will always be 1 second one 0-9, therefore just add modulo 10 and +1
            doubledigits += (doubled_digit % 10 + 1);
        }
        else
        {
            doubledigits += doubled_digit;
        }
        i++;
        if (i == digitcounts - 2)
        {
            last2digits += Creditnumber;
        }
        Creditnumber /= 10;
    }
    int lastint_sum = (notdoubledigit + doubledigits) % 10;

    if (lastint_sum != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // Test Case Visa
    else if (((last2digits / 10) == 4 || last2digits == 4) && (digitcounts == 13 || digitcounts == 16))
    {
        printf("VISA\n");
        return 0;
    }
    // Test Case Mastercard
    else if ((last2digits == 51 || last2digits == 52 || last2digits == 53 || last2digits == 54 || last2digits == 55) && digitcounts == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    // Test Case AMEX
    else if ((last2digits == 34 || last2digits == 37) && (digitcounts == 15))
    {
        printf("AMEX\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
    }
}

int digitcount(long num)
{
    int counter = 0;
    if (num == 0)
    {
        return 1;
    }
    while (num != 0)
    {
        num /= 10;
        counter++;
    }
    return counter;
}
