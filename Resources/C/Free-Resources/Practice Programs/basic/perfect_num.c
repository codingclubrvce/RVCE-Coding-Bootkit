/*
Question: Write a program to check if a given number is a perfect number.

Description:
Create a program that checks whether a number is a perfect number. A perfect number is a positive integer that is equal to the sum of its proper divisors (excluding itself).
For example:
- 6 is perfect (1 + 2 + 3 = 6)
- 28 is perfect (1 + 2 + 4 + 7 + 14 = 28)
- 12 is not perfect (1 + 2 + 3 + 4 + 6 = 16)

Input:
1. A positive integer number

Output:
1. Print whether the number is a perfect number or not

Note: The program should only consider positive integers.
*/

#include <stdio.h>

int main()
{
    int num, divisor_sum = 0;

    printf("Enter a number:  ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            divisor_sum += i;
        }
    }

    if (divisor_sum == num) 
    {
        printf("%d is a Perfect Number\n", num);
    } 
    
    else 
    {
        printf("%d is not a Perfect Number\n", num);
    }

    return 0;
}