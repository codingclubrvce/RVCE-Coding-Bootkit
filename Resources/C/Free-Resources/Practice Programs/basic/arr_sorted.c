/*
Question: Write a program to check if an array is sorted in ascending or descending order.

Description:
Create a program that determines whether the elements in an array are sorted in ascending order,
descending order, or not sorted at all.
For example:
- [1, 2, 3, 4, 5] is sorted in ascending order
- [5, 4, 3, 2, 1] is sorted in descending order
- [1, 3, 2, 4, 5] is not sorted

Input:
1. Size of the array (n)
2. n elements of the array

Output:
1. Whether the array is:
   - Sorted in ascending order
   - Sorted in descending order
   - Not sorted

Note: Consider array with same elements (like [1,1,1]) as sorted in both ascending and descending order
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n;
    int ascending_count = 0, descending_count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] > arr[i + 1]) 
        {
            descending_count++;
        }

        else if (arr[i] < arr[i + 1])
        {
            ascending_count++;
        }

        else if (arr[i] == arr[i + 1])
        {
            ascending_count++;
            descending_count++;
        }
    }

    if (ascending_count == (n - 1)) 
    {
        printf("The array is in ascending order.\n");
    }

    else if (descending_count == (n - 1))
    {
        printf("The array is in descending order.\n");
    }

    else
    {
        printf("The array is not sorted.\n");
    }

    return 0;
}
