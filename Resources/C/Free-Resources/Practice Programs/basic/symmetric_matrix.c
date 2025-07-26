/*
Question: Write a program to check if a given square matrix is symmetric.

Description:
Create a program that checks whether a given n x n matrix is symmetric. A matrix is symmetric if it is equal to its transpose (i.e., element at [i][j] is equal to element at [j][i] for all i, j).
For example:
- 3x3 Symmetric matrix:
  1 2 3
  2 4 5
  3 5 6

Input:
1. Order of the matrix (n)
2. n x n elements of the matrix

Output:
1. Print whether the matrix is symmetric or not

Note: The program should work for any square matrix size.
*/

#include <stdio.h>

int main()
{
    int n, check = 0;
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
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] != matrix[j][i])
            {
                check = 1;
                break;
            }
        }

        if (check == 1)
        {
            printf("The given matrix is not symmetric\n");
            break;
        }
    }

    if (check == 0)
    {
        printf("The given matrix is symmetric\n");
    }

    return 0;
}