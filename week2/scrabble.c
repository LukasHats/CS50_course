#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculator(string word);
int ALPHABET_INT[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Word: ");
    string player2 = get_string("Word: ");

    // Player 1
    int sum_player1 = calculator(player1);
    int sum_player2 = calculator(player2);

    if (sum_player1 > sum_player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sum_player1 < sum_player2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int calculator(string word)
{
    int sum = 0;
    for (int i=0, n = strlen(word); i < n; i++)
        {
            if (isupper(word[i]))
            {
                sum += ALPHABET_INT[word[i] - 'A'];
            }
            else if (islower(word[i]))
            {
                sum += ALPHABET_INT[word[i] - 'a'];
            }
            else
            {
                sum += 0;
            }
        }
    return sum;
}

