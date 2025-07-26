/*
Question: Write a program to separate even and odd elements of an array into two different arrays.

Description:
Create a program that takes an array of integers as input and separates the even and odd elements into two new arrays.
For example:
- Array: [1, 2, 3, 4, 5, 6]
  Even array: [2, 4, 6]
  Odd array: [1, 3, 5]

Input:
1. Size of the array (n)
2. n elements of the array

Output:
1. Array of even elements
2. Array of odd elements

Note: The program should display both arrays after separation.
*/

#include <stdio.h>

int main() 
{
    int arr[100], even[100], odd[100];
    int n;
    int even_index = 0, odd_index = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);

        if(arr[i] % 2 == 0) 
        {
            even[even_index++] = arr[i];
        } 
        else 
        {
            odd[odd_index++] = arr[i];
        }
    }

    printf("Even elements: ");
    for(int i = 0; i < even_index; i++) 
    {
        printf("%d ", even[i]);
    }

    printf("\nOdd elements: ");
    for(int i = 0; i < odd_index; i++) 
    {
        printf("%d ", odd[i]);
    }

    printf("\n");

    return 0;
}
