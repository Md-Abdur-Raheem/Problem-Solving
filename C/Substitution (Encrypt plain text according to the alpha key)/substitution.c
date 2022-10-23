#include "../Libraries/cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encipher(string text, string key);
int check_repeat(string key);

int main(int argc, string argv[])
{
    string key;
    string plaintext;

    if (argc != 2) // to validate the cli argument
    {
        printf("Usage: ./substitution key\n"); // if no arg found or more than one arg found.
        return 1;
    }
    else if (strlen(argv[1]) != 26) // if there is more or less than 26 char.
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int is_repeat = check_repeat(argv[1]);

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i])) // to check all the char are alphabetic.
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (is_repeat) // to check if there is any duplicate char in the key.
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            continue;
        }
    }
    key = argv[1];

    plaintext = get_string("plaintext: ");
    encipher(plaintext, key);
}

int check_repeat(string key) // to chech if there is any duplicate char in the key.
{
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (key[i] == key[k])
            {
                return 1;
            }
        }
    }
    return 0;
}

void encipher(string text, string key) // function for plaintext to ciphertext
{
    printf("ciphertext: ");
    int c;
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i])) // to print ciphertext and avoid non-textual character
        {
            if (isupper(text[i]))
            {
                c = text[i] - 65; // to converst ascii to 0-25 number.

                printf("%c", toupper(key[c])); // to convert 0-26 number to ascii 65-90
            }
            else if (islower(text[i]))
            {
                c = text[i] - 97; // to converst ascii to 0-26 number.

                printf("%c", tolower(key[c])); // to convert 0-26 number to ascii 65-90
            }
        }
        else
        {
            printf("%c", text[i]); // to print any non-alphabatic character.
            continue;
        }
    }
    printf("\n");
}