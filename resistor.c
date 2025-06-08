#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* resistors(float r1, float r2, float r3)
{
    //Initialise array for all combinations
    float *arr = (float *)malloc(5 * sizeof(float));
    if (arr == NULL)
    {
        printf("Memory allocation failed.");
    }

    // Calculate series
    arr[0] = r1 + r2 + r3;

    // Calculate parallel
    arr[1] = 1/((1/r1) + (1/r2) + (1/r3));

    // Calculate combos
    arr[2] = r1 + (1/((1/r2) + (1/r3)));
    arr[3] = r2 + (1/((1/r1) + (1/r3)));
    arr[4] = (1/((1/r1) + (1/r2))) + r3;

    return arr;
}

int main(void)
{
    float *arr = resistors(3.1, 3.4, 6.5);
    for (int i = 0; i < 5; i++)
    {
        printf("The value is: %.2f\n", arr[i]);
    }

    free(arr);

    return (0);
}
