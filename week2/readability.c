#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Input long string from user == Text
    string text = get_string("Text: ");

    // get number of letters, islower/isupper ignores blanks and ! etc.
    // get number of words, this is equal to when we hit everything but a letter, then sum gets +1
    float letters = 0;
    for (int i=0, n = strlen(text); i < n; i++)
        {
            if (isalpha(text[i]))
            {
                letters++;
            }
        }

    //Calculate number of words
    float words = 1, inword = 0;
    for (int i =0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    // get number of sentences (per 100 words)
    float sentences = 0;
    for (int i =0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }

    // calculate Coleman Liau Index
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int index_rounded = (int) (index + 0.5);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index_rounded);
    }

}
