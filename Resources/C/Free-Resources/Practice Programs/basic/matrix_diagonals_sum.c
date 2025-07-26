/*
Question: Write a program to find the sum of the primary and secondary diagonals of a square matrix.

Description:
Create a program that takes a square matrix as input and calculates the sum of its primary (main) diagonal and secondary (anti) diagonal elements.
For example:
- For matrix:
  1 2 3
  4 5 6
  7 8 9
  Primary diagonal sum: 1 + 5 + 9 = 15
  Secondary diagonal sum: 3 + 5 + 7 = 15

Input:
1. Order of the square matrix (n)
2. n x n elements of the matrix

Output:
1. Sum of the primary diagonal
2. Sum of the secondary diagonal

Note: For odd n, the center element will be counted in both sums.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of the square matrix:  ");
    scanf("%d", &n);

    int matrix[n][n];
    int primary_sum = 0, secondary_sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        primary_sum += matrix[i][i];
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        secondary_sum += matrix[i][n - i - 1];
    }

    printf("\nSum of primary diagonal: %d\n", primary_sum);
    printf("\nSum of secondary diagonal: %d\n", secondary_sum);

    return 0;
}