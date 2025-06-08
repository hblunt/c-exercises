#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int reverse_words(char str[])
{
    int size = strlen(str);

    for (int i = size - 1; i > -1; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int is_palindrome(char str[], int start, int end)
{
    while (start > end)
    {
        if (str[start] != str[end]) return 0;
        start++;
        end--;
    }

    return 1;
}

void count_palindrome_words(char str[])
{
    int count = 0;
    int start = 0;
    int end = 0;
    int size = strlen(str);

    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            end = i - 1;
            count += is_palindrome(str, start, end);
            start = i + 1;
        }
    }
    printf("Palindromes: %d\n", count);
}

void encode_rot13(char str[])
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        str[i] += 13;
        printf("%c", str[i]);
    }
    printf("\n");
}

void validate_email(char str[])
{
    if (str[0] < 'a' || str[0] > 'z')
    {
        printf("Invalid email.\n");
        return;
    }

    int size = strlen(str);
    for (int i = 1; i < size; i++)

    if (str[i] == '@')
    {
        for (int j = i; j < size; j++)
        {
            if (str[j] == '.' && str[j+1] > 'a' && str[j] < 'z')
            {
                printf("Valid email.\n");
                return;
            }
        }
    }
    printf("Invalid email.\n");
    return;
}



int main(void)
{
    char string[] = "hello";
    char string2[] = "racecar bum";
    char string3[] = "yoyo@email.com";

    reverse_words(string3);
    count_palindrome_words(string2);
    encode_rot13(string);
    validate_email(string3);


    return (0);
}
