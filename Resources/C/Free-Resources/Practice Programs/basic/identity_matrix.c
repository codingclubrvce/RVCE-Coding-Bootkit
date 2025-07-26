/*
Question: Write a program to check if a given square matrix is an identity matrix.

Description:
Create a program that checks whether a given n x n matrix is an identity matrix. An identity matrix has 1s on the main diagonal and 0s elsewhere.
For example:
- 3x3 Identity matrix:
  1 0 0
  0 1 0
  0 0 1

Input:
1. Order of the matrix (n)
2. n x n elements of the matrix

Output:
1. Print whether the matrix is an identity matrix or not

Note: The program should work for any square matrix size.
*/

#include <stdio.h>

int main()
{
    int n, check = 0;
    printf("Enter the order of the square matrix:  ");
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);

            if (i == j && matrix[i][j] != 1)
            {
                check = 1;
            }

            else if (i != j && matrix[i][j] != 0)
            {
                check = 1;
            }
        }
    }

    if (check == 0)
    {
        printf("The given matrix is an identity matrix\n");
    }

    else
    {
        printf("The given matrix is not an identity matrix\n");
    }

    return 0;
}