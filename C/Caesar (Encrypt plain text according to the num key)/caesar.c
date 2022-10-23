#include "../Libraries/cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void make_cipher(string text, int key);

int main(int argc, string argv[])
{

    int key;
    string plain_text;
    string arg = argv[1];

    if (argc == 2) // to validate the cli argument
    {
        for (int i = 0; i < strlen(arg); i++)
        {
            if (arg[i] >= 48 && arg[i] <= 57)
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
                break;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    key = atoi(arg); // to convert string argument to integer.

    plain_text = get_string("plaintext: ");

    make_cipher(plain_text, key);
}

void make_cipher(string text, int key) // function for plaintext to ciphertext
{
    char c;
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        // to print ciphertext and avoid non-textual character
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {

                if ((text[i] + key > 90 && text[i] + key < 97) || text[i] + key < 65) // to check if the new character cross the ascii limit
                {
                    c = (text[i] - 65 + key) % 26; // to converst ascii to 0-26 number.
                    printf("%c", 65 + c);          // to convert 0-26 number to ascii 65-90
                }
                else
                {
                    printf("%c", text[i] + key);
                }
            }
            else if (islower(text[i]))
            {

                if (text[i] + key > 122 || (text[i] + key < 97 && text[i] + key > 90)) // to check if the new character cross the ascii limit
                {
                    c = (text[i] - 97 + key) % 26; // to converst ascii to 0-26 number.
                    printf("%c", 97 + c);          // to convert 0-26 number to ascii 97-122
                }
                else
                {
                    printf("%c", text[i] + key); // to print char between the ascii range.
                }
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
