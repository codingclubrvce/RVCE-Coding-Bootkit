/*
Question: Write a program to count the number of non-zero elements in a matrix.

Description:
Create a program that takes a matrix as input and counts how many elements in the matrix are not zero.
For example:
- Matrix:
  1 0 2
  0 0 3
  4 5 0
  Non-zero elements: 1, 2, 3, 4, 5 (count = 5)

Input:
1. Number of rows
2. Number of columns
3. Matrix elements (row-wise)

Output:
1. Number of non-zero elements in the matrix

Note: The program should work for any matrix size.
*/

#include <stdio.h>

int main()
{
    int rows, columns, count = 0;
    printf("Enter the number of rows and columns of the matrix:  ");
    scanf("%d %d", &rows, &columns);

    int matrix[rows][columns];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }

    printf("\nThe number of non-zero elements in the given matrix are:  %d\n", count);

    return 0;
}