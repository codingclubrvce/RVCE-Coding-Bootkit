/*
Question: Write a program to count the number of digits in a given number.

Description:
Create a program that counts how many digits are present in a given integer number.
For example:
- Number: 12345 has 5 digits
- Number: 700 has 3 digits
- Number: 7 has 1 digit

Input:
1. An integer number

Output:
1. Number of digits in the given number

Note: Handle both positive and negative numbers
*/

#include <stdio.h>

int main()
{
	int num, digit_count = 0;
	printf("Enter a number:  ");
	scanf("%d", &num);

	for (int i = 1; i < num; i *= 10)
	{
		digit_count++;
	}
	
	printf("The number of digits in %d is %d\n", num, digit_count);
	
	return 0;
}