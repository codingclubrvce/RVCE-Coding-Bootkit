/*
Question: Write a program to find the difference between minimum and maximum elements in an array.

Description:
Create a program that finds the largest and smallest elements in an array and calculates their difference.
For example:
- Array: [10, 5, 8, 12, 3]
- Maximum element: 12
- Minimum element: 3
- Difference: 12 - 3 = 9

Input:
1. Size of the array (n)
2. n elements of the array

Output:
1. Maximum element in the array
2. Minimum element in the array
3. Difference between maximum and minimum elements

Note: The program should work with both positive and negative numbers.
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n;
    int max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];

    for(int i = 1; i < n; i++) 
    {
        if(arr[i] > max) 
        {
            max = arr[i];
        }

        if(arr[i] < min) 
        {
            min = arr[i];
        }
    }

    int diff = max - min;
    printf("Difference between max and min: %d\n", diff);

    return 0;
}
