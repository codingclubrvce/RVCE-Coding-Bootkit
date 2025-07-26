/*
Question: Write a program to check whether a given number is prime or not.

Description:
Create a program that determines if a given integer is a prime number. A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.
For example:
- 7 is prime (divisors: 1, 7)
- 10 is not prime (divisors: 1, 2, 5, 10)

Input:
1. An integer number

Output:
1. Print whether the number is prime or not

Note: Handle both positive and negative numbers, and display appropriate message for numbers less than 2.
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int num, num_sqrt;
	printf("Enter a number: ");
	scanf("%d", &num);
	num_sqrt = sqrt(num);
	
	if (num < 2)
	{
		printf("%d is not prime\n", num);
		return 0;
	}
	
	else if (num == 2)
	{
		printf("%d is prime\n", num);
		return 0;
	}
	
	else 
	{
		for (int i = 2; i <= (num_sqrt + 1); i++)
		{
			if (num % i == 0)
			{
				printf("%d is not prime\n", num);
				return 0;
			}
		}
	}
	
	printf("%d is prime\n", num);
	return 0;
}