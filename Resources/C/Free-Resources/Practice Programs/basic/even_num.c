/*
Question: Write a program to print all even numbers from 0 up to a given number n.

Description:
Create a program that takes a positive integer n as input and prints all even numbers from 0 to n (inclusive).
For example:
- If n = 10, output: 0 2 4 6 8 10
- If n = 7, output: 0 2 4 6

Input:
1. A positive integer n

Output:
1. All even numbers from 0 to n (inclusive), separated by spaces

Note: The output should be in a single line, and 0 should be included as even.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\n");
    
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    
    printf("are even numbers\n");
    
    return 0;
}