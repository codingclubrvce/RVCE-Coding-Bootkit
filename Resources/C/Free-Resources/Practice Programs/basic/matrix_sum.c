/*
Question: Write a program to find the element-wise sum of two square matrices.

Description:
Create a program that takes two square matrices of the same order as input and prints their sum matrix (element-wise addition).
For example:
- Matrix A:
  1 2
  3 4
- Matrix B:
  5 6
  7 8
- Sum Matrix:
  6 8
 10 12

Input:
1. Order of the square matrix (n)
2. n x n elements of the first matrix
3. n x n elements of the second matrix

Output:
1. The sum matrix (element-wise addition)

Note: The program should display the resulting matrix in proper format.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of the square matrix:  ");
    scanf("%d", &n);

    int matrix1[n][n], matrix2[n][n], matrix_sum[n][n];

    printf("\nEnter the first matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
            matrix_sum[i][j] = matrix1[i][j];
        }
    }

    printf("\nEnter the second matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
            matrix_sum[i][j] += matrix2[i][j];
        }
    }

    printf("\nThe matrix sum is:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix_sum[i][j]);
        }   
        printf("\n");
    }

    return 0;
}