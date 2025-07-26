/*
Question: Write a program to print a right-angled triangle pattern of increasing numbers in each row.

Description:
Create a program that prints a right-angled triangle where each row contains numbers starting from 1 up to the row number.
For example:
- For n = 5, output:
  1
  1 2
  1 2 3
  1 2 3 4
  1 2 3 4 5

Input:
1. Number of rows (n)

Output:
1. The triangle pattern as described above

Note: Each row should start on a new line and numbers should be separated by spaces.
*/

#include <stdio.h>

int main() 
{
    for (int i = 1; i <= 5; i++) 
	{
        for (int j = 1; j <= i; j++) 
		{
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
