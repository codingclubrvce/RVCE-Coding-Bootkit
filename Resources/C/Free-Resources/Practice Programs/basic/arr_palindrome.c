/*
Question: Write a program to check if an array is palindrome or not.

Description:
Create a program that determines whether the elements in an array read the same forwards and backwards.
For example:
- Array [1, 2, 3, 2, 1] is a palindrome
- Array [1, 2, 3, 3, 2, 1] is a palindrome
- Array [1, 2, 3, 4] is not a palindrome

Input:
1. Size of the array (n)
2. n elements of the array

Output:
1. Print whether the array is a palindrome or not
2. Display the array elements

Note: Array elements should be compared from both ends moving towards the center.
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n, is_palindrome = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++) 
    {
        if (arr[i] != arr[n - 1 - i]) 
        {
            is_palindrome = 0;
            printf("The array is not a palindrome.\n");
            break;
        }
    }

    if (is_palindrome == 1) 
    {
        printf("The array is a palindrome.\n");
    }

    return 0;
}
