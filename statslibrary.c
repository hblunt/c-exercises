#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float harmonic_mean(float arr[], int size)
{
    float denominator = 0;

    for(int i = 0; i < size; i++)
    {
        denominator += 1/arr[i];
    }

    return size / denominator;
}

float geometric_mean(float arr[], int size)
{
    float internal = 1;
    for(int i = 0; i < size; i++)
    {
        internal *= arr[i];
    }

    return pow(internal, 1.0/size);
}

void remove_outliers(float arr[], int *size, float threshold)
{
    float sum = 0;
    for(int i = 0; i < *size; i++)
    {
        sum += arr[i];
    }

    float mean = sum / *size;

    for(int i = 0; i < *size; i++)
    {
        if (fabs(arr[i] - mean) > threshold)
        {
            for (int j = i; j < *size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            i--;
        }
    }
}

void find_mode(float arr[], int size)
{
    int maxCount = -1;
    int indices = 0;

    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            indices = i;
        }
    }

    printf("The mode is %.2f, which occured %d times\n", arr[indices], maxCount);
}

int main(void)
{
    int size = 7;
    float arr[7] = {2.3, 3.3, 5.1, 3.3, 7.8, 8.4, 6.6};

    printf("%.2f\n", harmonic_mean(arr, size));
    printf("%.2f\n", geometric_mean(arr, size));

    find_mode(arr, size);

    return (0);
}

