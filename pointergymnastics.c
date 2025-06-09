#include <stdio.h>
#include <stdlib.h>

void swap_arrays(int arr1[], int arr2[], int size)
{
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }
    printf("Arrays swapped.\n");
}

void find_substring(char *str, char *sub)
{
    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }

    int subSize = 0;
    while (sub[subSize] != '\0')
    {
        subSize++;
    }

    int matches = 0;

    printf("Size and sub-size: %d and %d\n", size, subSize);

    for(int i = 0; i < size; i++)
    {
        if(str[i] == sub[i] && matches < subSize)
        {
            matches++;
            if (matches == subSize)
            {
                printf("Substring found at index %d\n", i-subSize+1);
                return;
            }
        } else matches = 0;
    }
    printf("Substring not found.\n");
}

void reverse_array(char *arr, int size)
{
    for(int i = size; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

void *mem_cpy(void *dest, const void *src, size_t n)
{
    char *dest_ptr = (char *)(dest);
    char *src_ptr = (char *)(src);
    for(int i =  0; i < n; i++)
    {
        dest_ptr[i] = src_ptr[i];
    }
    return dest;
}

int main(void)
{
    int arr1[5] = {3, 4, 8, 7, 6};
    int arr2[5] = {9, 4, 0, 9, 2};
    char str[] = "hello";
    char sub[] = "he";
    char dest[8];

    swap_arrays(arr1, arr2, 5);
    find_substring(str, sub);
    reverse_array(str, 5);
    mem_cpy(dest, str, 5 * sizeof(char));
    printf("%c\n", dest[0]);

    return (0);
}
