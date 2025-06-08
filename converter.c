#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binary(int num)
{
    int binary[32];
    int i = 0;
    while(num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}

void octal(int num)
{
    int octal[32];
    int i = 0;
    while (num > 0)
    {
        octal[i] = num % 8;
        num = num / 8;
        i++;
    }

    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
}

void hex(int num)
{
    char hex[32];
    int i = 0;
    while (num > 0)
    {
        int newNum = num % 16;
        if (newNum > 9)
        {
            if (newNum == 10) hex[i] = 'A';
            if (newNum == 11) hex[i] = 'B';
            if (newNum == 12) hex[i] = 'C';
            if (newNum == 13) hex[i] = 'D';
            if (newNum == 14) hex[i] = 'E';
            if (newNum == 15) hex[i] = 'F';
        } else hex[i] = newNum + '0';
        num /= 16;
        i++;
    }

    for(int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
}

int main(void)
{
    int num;
    int choice;
    printf("Enter an integer number: ");
    scanf(" %d", &num);

    printf("What form would you like to convert number to?\n1 - Binary\n2 - Octal\n3 - Hexadecimal\nChoice: ");
    scanf(" %d", &choice);

    switch(choice)
    {
    case 1:
        binary(num);
        break;
    case 2:
        octal(num);
        break;
    case 3:
        hex(num);
        break;
    }

    return (0);
}
