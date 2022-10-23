#include <stdio.h>
#include <math.h>

int check_sum(long long);
int check_length(long long);
int check_first_digit(long long);
int check_first_two_digits(long long);
char *check_brand(int, long long);

int main(void)
{
    long long credit_card;

    // taking credit card number from user.
    do
    {
        printf("Enter your credit card number: \n");
        scanf("%lld", &credit_card);
    } while (credit_card <= 0);

    int is_valid = check_sum(credit_card); // checking check sum validity.

    int length = check_length(credit_card); // checking length of the credit card.

    if (is_valid) // checking brand validity.
    {
        char *brand = check_brand(length, credit_card);
        printf("%s\n", brand);
    }
    else
    {
        printf("INVALID");
    }
}

int check_sum(long long credit_card) // function for chcking the check sum
{
    int sum = 0;
    long long working_cc = credit_card;

    // to add all the other digits from last.
    while (working_cc > 0)
    {
        int last_digit = working_cc % 10;
        sum = sum + last_digit;
        working_cc = working_cc / 100;
    }

    // to add all the other digits from the 2nd last.
    working_cc = credit_card / 10;

    while (working_cc > 0)
    {
        int last_digit = working_cc % 10;
        int times = last_digit * 2;
        sum = sum + (times % 10) + (times / 10);
        working_cc = working_cc / 100;
    }

    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_length(long long credit_card) // function for measure the length of the card
{
    long long working_cc = credit_card;
    int i = 0;
    while (working_cc != 0)
    {
        working_cc = working_cc / 10;
        i++;
    }
    return i;
}

int check_first_digit(long long credit_card) // function for get first digit of the card.
{
    int length = check_length(credit_card);
    int first_digit = credit_card / pow(10, length - 1);
    return first_digit;
}

int check_first_two_digits(long long credit_card) // function for get first two digits of the card.
{
    int length = check_length(credit_card);
    int first_two_digits = credit_card / pow(10, length - 2);
    return first_two_digits;
}

char *check_brand(int length, long long credit_card) // function for check the brand of the card.
{
    int first_digit = check_first_digit(credit_card);
    int first_two_digits = check_first_two_digits(credit_card);

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return "MASTER CARD";
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}