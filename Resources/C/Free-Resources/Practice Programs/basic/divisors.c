/*
Question: Write a program to find all divisors of a given number.

Description:
Create a program that finds and displays all numbers that perfectly divide the given number.
For example:
- For number 12:
  Divisors are: 1, 2, 3, 4, 6, 12
- For number 15:
  Divisors are: 1, 3, 5, 15

Input:
1. A positive integer

Output:
1. All divisors of the given number in ascending order

Note: Include both 1 and the number itself as divisors
*/

#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number:  ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}