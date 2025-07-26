/*
Question: Write a program to print all prime numbers within a given range.

Description:
Create a program that takes two integers as input and prints all prime numbers between them (inclusive).
For example:
- Input: 10, 20 → Output: 11 13 17 19
- Input: 1, 10 → Output: 2 3 5 7

Input:
1. Two integers representing the lower and upper bounds of the range

Output:
1. All prime numbers within the specified range, separated by spaces

Note: The program should handle cases where the lower bound is greater than the upper bound and should only print primes for valid ranges.
*/

#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
	int num_sqrt = sqrt(num);
	
	if (num < 2)
	{
		return 0;
	}
	
	else if (num == 2)
	{
		return 1;
	}
	
	else 
	{
		for (int i = 2; i <= (num_sqrt + 1); i++)
		{
			if (num % i == 0)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

int main()
{
    int start, end;

    printf("Enter the starting and ending numbers:  ");
    scanf("%d %d", &start, &end);

    for (int i = start; i <= end; i++)
    {
        if (is_prime(i) == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}