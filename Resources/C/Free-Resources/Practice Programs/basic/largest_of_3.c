/*
Question: Write a program to find the largest among three numbers.

Description:
Create a program that takes three integer numbers as input and determines which one is the largest.
For example:
- Input: 5, 9, 3 → Output: 9 is the largest
- Input: -2, -7, -1 → Output: -1 is the largest

Input:
1. Three integer numbers

Output:
1. The largest number among the three

Note: If two or more numbers are equal and largest, print that value as the largest.
*/

#include <stdio.h>

int main() 
{
    int a, b, c;

    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c) 
	{
        printf("The largest number is: %d\n", a);
    }
    else if (b >= a && b >= c) 
	{
        printf("The largest number is: %d\n", b);
    }
    else 
	{
        printf("The largest number is: %d\n", c);
    }

    return 0;
}
