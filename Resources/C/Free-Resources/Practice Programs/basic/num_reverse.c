/*
Question: Write a program to reverse the digits of a given number.

Description:
Create a program that takes an integer as input and prints its digits in reverse order.
For example:
- Input: 12345 → Output: 54321
- Input: -678 → Output: -876

Input:
1. An integer number

Output:
1. The reversed number

Note: The program should handle both positive and negative numbers.
*/

#include <stdio.h>
#include <math.h>

int digit_count(int n)
{
    int count = 0;
	for (int i = 1; i < n; i *= 10)
	{
		count++;
	}
    return count;
}

int main()
{
    int num, num_copy;
    printf("Enter a number: ");
    scanf("%d", &num);

    num_copy = num;
    int num_length = digit_count(num);
    int reversed_digits[num_length];

    for (int i = 1; i <= num_length; i++)
    {
        reversed_digits[num_length - i] = num_copy / (int)pow(10, num_length - i);
        num_copy %= (int)pow(10, num_length - i);
    }

    for (int i = 0; i < num_length; i++)
    {
        printf("%d", reversed_digits[i]);
    }

    printf("\n");
    return 0;
}