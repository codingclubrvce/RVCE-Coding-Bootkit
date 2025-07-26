/*
Question: Write a program to reverse elements of an array in-place.

Description:
Create a program that reverses the elements of an array without using any additional array.
For example:
- Original array: [1, 2, 3, 4, 5]
- After reversal: [5, 4, 3, 2, 1]

Input:
1. Size of the array (n)
2. n elements of the array

Output:
1. Original array elements
2. Array elements after reversal

Note: The reversal should be done in-place (without using extra array)
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++) 
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
