#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_nums()
{
    int num;
    int total = 0;
    int odd = 0;
    int even = 0;
    int sum = 0;
    int max = -100000;
    int maxprev = 0;
    int min = 100000;
    int capacity = 100;
    int primetotal = 0;

    int *arr = (int * )malloc(5 * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed");
    }

    int *nums = (int * )malloc(100 * sizeof(int));
    if (nums == NULL)
    {
        printf("Memory allocation failed");
    }

    int *primes = (int * )malloc(100 * sizeof(int));
    if (primes == NULL)
    {
        printf("Memory allocation failed");
    }

    do {
        printf("Enter a number: ");
        scanf(" %d", &num);
        nums[total] = num;
        sum += num;
        if (num % 2 == 0){
            even++;
        } else odd ++;

        if (num > max)
        {
            maxprev = max;
            max = num;
        }
        if (num < min && num != -999) min = num;

        total++;

        if (total >= capacity)
        {
            capacity *= 2;
            nums = realloc(nums, capacity * sizeof(int));
            primes = realloc(primes, capacity * sizeof(int));
        }

    } while(num != -999);

    sum -= -999;
    int size = total - 1;

    arr[0] = sum;
    arr[1] = sum / size;
    arr[2] = max;
    arr[3] = min;
    arr[4] = maxprev;

    // Prime checking
        for(int i = 0; i < size; i++)
        {
            if (nums[i] <= 1) continue;
            int is_prime = 1;

            for (int j = 2; j * j <= nums[i]; j++)
            {
                if (nums[i] % j == 0) {
                    is_prime = 0;
                    break;
                }
            }

            if (is_prime)
            {
                primes[primetotal] = nums[i];
                primetotal++;
            }
        }

    for(int i = 0; i < 5; i++)
    {
        printf("The results of the array: %d\n", arr[i]);
    }

    printf("The prime numbers are: ");
    for(int i = 0; i < primetotal; i++)
    {
        printf("%d ", primes[i]);
    }

    free(arr);
    free(nums);
    free(primes);

}

int main(void)
{
    read_nums();

    return (0);
}
