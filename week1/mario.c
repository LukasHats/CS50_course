#include <stdio.h>
#include <cs50.h>

void paster(int rows);

int main(void)
{
    int size;
    do
    {
        size = get_int("How tall should the Pyramid be? Choose between 1 and 8 ");
    }
    while (size < 1 || size > 8);

    int rows;

    for (rows = 1; rows <= size; rows++)
    {
        for (int x = 1; x < size + 1 - rows; x++)
        {
            printf(" ");
        }
        paster(rows);
        printf("  ");
        paster(rows);
        printf("\n");
    }
}
void paster(int rows)
{
    for (int column = 0; column < rows; column++)
    {
        printf("#");
    }
}
