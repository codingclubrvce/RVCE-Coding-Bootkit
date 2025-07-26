/*
Question: Write a program to check whether a given number is a palindrome.

Description:
Create a program that checks if a given integer reads the same forwards and backwards (palindrome).
For example:
- Input: 121 → Output: Palindrome
- Input: 123 → Output: Not a palindrome
- Input: -121 → Output: Not a palindrome (if negative numbers are not considered palindromes)

Input:
1. An integer number

Output:
1. Print whether the number is a palindrome or not

Note: The program should handle both positive and negative numbers as per your requirements.
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

int reverse_num(int num)
{
    int num_copy = num, result = 0;
    int num_length = digit_count(num);
    int reversed_digits[num_length];

    for (int i = 1; i <= num_length; i++)
    {
        reversed_digits[num_length - i] = num_copy / (int)pow(10, num_length - i);
        num_copy %= (int)pow(10, num_length - i);
    }

    for (int i = 0; i < num_length; i++)
    {
        result += reversed_digits[i] * (int)pow(10, num_length - i - 1);
    }

    return result;
}

int main()
{
    int n;
    printf("Enter a number:  ");
    scanf("%d", &n);
    printf("%d\n", reverse_num(n));
    if (n == reverse_num(n))
    {
        printf("%d is a Palindrome\n", n);
    }

    else
    {
        printf("%d is not a Palindrome\n", n);
    }
}