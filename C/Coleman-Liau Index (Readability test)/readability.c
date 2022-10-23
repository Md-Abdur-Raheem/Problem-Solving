#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_grade(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int grade = count_grade(letters, words, sentences);

    if (grade >= 16) // checking the grade for 1-15
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text) // function for calculating the number of letters.
{
    int letters = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        else
        {
            continue;
        }
    }
    return letters;
}

int count_words(string text) // function for calculating the number of words.
{
    int words = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
        else
        {
            continue;
        }
    }
    return words + 1; // the last word of the text doesn't have any space that's why.
}

int count_sentences(string text) // function for calculating the number of sentences.
{
    int sentences = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
        else
        {
            continue;
        }
    }
    return sentences;
}

int count_grade(int letters, int words, int sentences) // function for calculating the grade.
{

    float l = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;

    int index = round(0.0588 * l) - (0.296 * s) - 15.8; // Coleman-Liau index formula
    // int index = round(value);

    return index;
}