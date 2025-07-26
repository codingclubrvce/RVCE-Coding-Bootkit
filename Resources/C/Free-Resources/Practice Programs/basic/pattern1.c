/*
Question: Write a program to print a right-angled triangle pattern of 1's.

Description:
Create a program that prints a right-angled triangle where each row contains only the number 1, and the number of 1's in each row equals the row number.
For example:
- For n = 4, output:
  1
  1 1
  1 1 1
  1 1 1 1

Input:
1. Number of rows (n)

Output:
1. The triangle pattern as described above

Note: Each row should start on a new line and numbers should be separated by spaces.
*/

#include <stdio.h>

int main() 
{
    for (int i = 1; i <= 4; i++) 
	{ 
        for (int j = 1; j <= i; j++) 
		{
            printf("1 ");
        }
        printf("\n");
    }

    return 0;
}
