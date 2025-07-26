/*
Question: Write a program to print Floyd's Triangle up to n rows.

Description:
Create a program that prints Floyd's Triangle, a right-angled triangular array of natural numbers, using the specified number of rows.
For example:
- For n = 4, output:
  1
  2 3
  4 5 6
  7 8 9 10

Input:
1. Number of rows (n)

Output:
1. Floyd's Triangle with n rows, filled with consecutive natural numbers starting from 1

Note: Each row should start on a new line and numbers should be separated by spaces.
*/

#include <stdio.h>

int main() 
{
    int rows, x = 1;

    printf("Enter the number of rows:  ");
    scanf("%d", &rows);

    printf("\n\n");

    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("%d ", x);
            x++;
        }
        
        printf("\n");
    }

    return 0;
}
