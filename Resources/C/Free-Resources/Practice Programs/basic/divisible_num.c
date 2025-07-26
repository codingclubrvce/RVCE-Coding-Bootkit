/*
Question: Write a program to find numbers divisible by given pairs of numbers in a range.

Description:
Create a program that prints all numbers from 1 to n that are:
a) Divisible by both 2 and 5
b) Divisible by both 3 and 5
For example:
- For n = 20:
  - Numbers divisible by 2 and 5: 10, 20
  - Numbers divisible by 3 and 5: 15

Input:
1. Upper limit n (positive integer)

Output:
1. Numbers divisible by both 2 and 5
2. Numbers divisible by both 3 and 5

Note: Organize the output in two separate lists for better readability
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\n");
    
    for (int i = 1; i <= (n / 10); i++)
    {
        printf("%d ", (i * 10));
    }
    if ((n / 10) > 0)
        printf("are divisible by both 2 and 5\n");
    
    for (int i = 1; i <= (n / 15); i++)
    {
        printf("%d ", (i * 15));
    }
    if ((n / 15) > 0)
        printf("are divisible by both 3 and 5\n");
    
    return 0;
}