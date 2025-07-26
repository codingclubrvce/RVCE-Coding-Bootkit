/*
Question: Write a program to check if a given number is an Armstrong number.

Description:
An Armstrong number is a number that is equal to the sum of its own digits raised to the power of the number of digits.
For example:
- 153 is an Armstrong number because: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
- 371 is an Armstrong number because: 3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371

Input:
- A positive integer number

Output:
- Print whether the given number is an Armstrong number or not
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
    int num, num_copy, result = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    num_copy = num;
    int num_length = digit_count(num);
    int reversed_digits[num_length];

    for (int i = 1; i <= num_length; i++)
    {
        result += pow((num_copy / (int)pow(10, num_length - i)), 3);
        num_copy %= (int)pow(10, num_length - i);
    }

    if (result == num)
    {
        printf("%d is an Armstrong Number\n", num);
    }

    else 
    {
        printf("%d is not an Armstrong Number\n", num);
    }

    return 0;
}