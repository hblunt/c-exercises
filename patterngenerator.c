#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pattern_generator()
{
    char input;
    int num;
    printf("Choose one of 3 patterns to generate, enter A, B or C: ");
    scanf(" %c", &input);
    printf("\nNow enter a number (0-100): ");
    scanf(" %d", &num);

    switch(input){
    case 'A':
        for(int i = 0; i < num; i++)
        {
            for (int j = 1; j < i + 2; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        break;

    case 'B':
        for(int i = 0; i < num; i++)
        {
            for (int j = i+1; j < (i+1+num); j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        break;

    case 'C':
        for(int i = 0; i < num; i++)
        {
            for (int j = i+1; j >= 1; j--)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        break;

    default:
        printf("Invalid choice, using pattern A by default.\n");
        for(int i = 0; i < num; i++)
        {
            for (int j = 1; j < i + 2; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        break;
    }
}

int main(void)
{
    pattern_generator();
    return (0);
}
