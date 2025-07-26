/*
Question: Write a program to input and display a matrix of user-defined dimensions.

Description:
Create a program that takes the number of rows and columns as input, then reads the elements of the matrix and displays it in matrix form.
For example:
- Input: 2 rows, 3 columns
  Elements: 1 2 3 4 5 6
  Output:
  1 2 3
  4 5 6

Input:
1. Number of rows
2. Number of columns
3. Matrix elements (row-wise)

Output:
1. The matrix displayed in proper row and column format

Note: The program should work for any positive dimensions.
*/

#include <stdio.h>

int main()
{
    int rows, columns;
    printf("Enter the number of rows and columns of the matrix:  ");
    scanf("%d %d", &rows, &columns);

    int matrix[rows][columns];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nYour matrix is:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }   
        printf("\n");
    }

    return 0;
}