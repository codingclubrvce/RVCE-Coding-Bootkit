/*
Question: Write a program to print the first n terms of the Fibonacci series.

Description:
Create a program that prints the first n terms of the Fibonacci sequence, where each term is the sum of the two preceding ones, starting from 0 and 1.
For example:
- For n = 5, output: 0 1 1 2 3
- For n = 8, output: 0 1 1 2 3 5 8 13

Input:
1. A positive integer n (number of terms)

Output:
1. The first n terms of the Fibonacci series, separated by spaces

Note: The sequence should start with 0 and 1.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of terms to be printed:  ");
    scanf("%d", &n);

    int fib_arr[n];
    fib_arr[0] = 0;
    fib_arr[1] = 1;
    for (int i = 2; i < n; i++) 
    {
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib_arr[i]);
    }

    printf("\n");
    return 0;
}