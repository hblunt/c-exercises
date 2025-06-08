#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void matrix(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void read_matrix(int arr1[][3], int arr2[][3])
{
    printf("Matrix A:\n");
    matrix(arr1);
    printf("\n");
    printf("Matrix B:\n");
    matrix(arr2);
    printf("\n");
}

void mulitply_matrices(int arr1[][3], int arr2[][3])
{
    printf("Matrices multiplied:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
    printf("\n");
}

void determinant(int arr[][3])
{
    int determinant = 0;

    determinant += arr[0][0]*(arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2])
    -   arr[0][1]*(arr[1][0]*arr[2][2] - arr[1][2]*arr[2][0])
    +   arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]);

    printf("Determinant of this array is: %d\n", determinant);
}

void transpose(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void is_symmetric(int arr[][3])
{
    bool check = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != arr[j][i]) {
                check = false;
                break;
            }
        }
        if (!check) break;
    }
    if(check) { printf("Matrix is symmetric.\n"); }
    else printf("Matrix not symmetric.\n");
}

int main(void)
{
    int A[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    int B[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
    };

    read_matrix(A, B);
    mulitply_matrices(A, B);
    determinant(A);
    transpose(B);
    is_symmetric(A);


    return (0);
}
