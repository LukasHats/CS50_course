#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** keys)
{
    if (argc != 2 || strlen(keys[1]) != 26)
    {
        printf("ERROR, please prompt a key with 26 unique letters, no special characters");
        return 1;
    }

    string key = keys[1];
    // Check for correct type of input and if unique
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("ERROR, please propmt a valid letter from a to z");
            return 1;
        }


        for (int j = i + 1; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                printf("Error, please prompt only unique characters");
                return 1;
            }
        }
    }
    string text = get_string("plaintext: ");
    char output[strlen(text)+1];
    for (int k = 0, j = strlen(text); k < j; k++)
    {
        if (isupper(text[k]))
        {
            output[k] = toupper(key[text[k] - 'A']);
        }
        else if (islower(text[k]))
        {
            output[k] = tolower(key[text[k] - 'a']);
        }
        else
        {
            output[k] = text[k];
        }
    output[strlen(text)] = '\0';

    }
    printf("ciphertext: %s\n", output);
    return 0;
}

