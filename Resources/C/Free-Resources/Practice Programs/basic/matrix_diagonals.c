/*
Question: Write a program to print the elements of the primary and secondary diagonals of a square matrix.

Description:
Create a program that takes a square matrix as input and prints the elements of its primary (main) diagonal and secondary (anti) diagonal.
For example:
- For matrix:
  1 2 3
  4 5 6
  7 8 9
  Primary diagonal: 1 5 9
  Secondary diagonal: 3 5 7

Input:
1. Order of the square matrix (n)
2. n x n elements of the matrix

Output:
1. Elements of the primary diagonal
2. Elements of the secondary diagonal

Note: For odd n, the center element will appear in both diagonals.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of the square matrix:  ");
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nElements of primary diagonal: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", matrix[i][i]);
    }

    printf("\nElements of secondary diagonal: \n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", matrix[i][n - i - 1]);
    }

    return 0;
}