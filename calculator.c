#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void memoryManagement();
float *memory = NULL;
int capacity = 100;
int counter = 0;

float add(float a, float b)
{
    float result = a + b;
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

float subtract(float a, float b)
{
    float result = a - b;
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

float multiply(float a, float b)
{
    float result = a * b;
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

float modulo(float a, float b)
{
    float result = fmod(a, b);
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

float power(float base, float exp)
{
    float result = pow(base, exp);
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

float square_root(float a) {
    if (a < 0)
    {
        printf("Error: Cannot take square root of negative number!\n");
    }
    float result = sqrt(a);
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

float divide(float a, float b)
{
    if(b == 0)
    {
        printf("Cannot divide by zero.\n");
    }

    float result = a / b;
    memory[counter] = result;
    memoryManagement();
    counter++;
    return result;
}

void memoryManagement()
{
    if(counter >= capacity)
    {
        capacity *= 2;
        memory = realloc(memory, capacity * sizeof(float));
    }
}

void memory_recall()
{
    printf("Printing calculations in memory...\n");
    for(int i = 0; i < counter; i++)
    {
        printf("%.2f\n", memory[i]);
        if (i == counter - 1)
        {
            printf("\n");
        }
    }
}

void memory_store(float val)
{
    memory[counter] = val;
    counter++;
    printf("%.2f stored in memory\n", val);
}

void memory_clear()
{
    free(memory);
    printf("Memory cleared.\n");
}

void memory_add(float val)
{
    memory[counter - 1] += val;
    printf("Value added to most recent number in memory, new number is now %.2f\n", memory[counter - 1]);
}

int main(void)
{
    memory = (float * )malloc(capacity * sizeof(float));
    if (memory == NULL)
    {
        printf("Memory allocation failed");
    }

    while(1)
    {
        float a, b;
        int choice;
        printf("Enter two numbers: ");
        scanf(" %f %f", &a, &b);
        printf("Enter a operation from the list:\n1 - Add\n2 - Subtract\n3 - Mulitply\n4 - Divide\n5 - Modulo\n6 - Powers\n7 - Square root\n\nEnter your choice: ");
        scanf(" %d", &choice);

        switch(choice)
        {
        case 1:
            printf("Result: %.2f\n", add(a, b));
            break;
        case 2:
            printf("Result: %.2f\n", subtract(a, b));
            break;
        case 3:
            printf("Result: %.2f\n", multiply(a, b));
            break;
        case 4:
            printf("Result: %.2f\n", divide(a, b));
            break;
        case 5:
            printf("Result: %.2f\n", modulo(a, b));
            break;
        case 6:
            printf("Result: %.2f\n", power(a, b));
            break;
        case 7:
            printf("Result: %.2f\n", sqrt(a));
            break;
        default:
            printf("Not a valid choice.");
            return (0);
        }

        memory_store(5.5);
        memory_recall();
        memory_add(1.0);
        memory_recall();
        memory_clear();
    }

    free(memory);
}
