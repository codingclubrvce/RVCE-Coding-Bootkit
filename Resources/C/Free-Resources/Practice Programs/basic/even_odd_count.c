/*
Question: Write a program to count the number of even and odd elements in an array.

Description:
Create a program that takes an array of integers as input and counts how many elements are even and how many are odd.
For example:
- Array: [1, 2, 3, 4, 5]
  Even count: 2 (2, 4)
  Odd count: 3 (1, 3, 5)

Input:
1. Size of the array (n)
2. n elements of the array

Output:
1. Number of even elements
2. Number of odd elements

Note: The program should work for both positive and negative integers.
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n;
    int even_count = 0, odd_count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers:  ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        if(arr[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }

    printf("Even elements: %d\n", even_count);
    printf("Odd elements: %d\n", odd_count);

    return 0;
}
