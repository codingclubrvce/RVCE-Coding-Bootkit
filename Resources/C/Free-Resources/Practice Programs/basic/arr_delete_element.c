/*
Question: Write a program to delete an element from a specific position in an array.

Description:
Create a program that removes an element from a given position in an array and shifts all subsequent elements to fill the gap.
For example:
- Original array: [1, 2, 3, 4, 5]
- Delete element at position 2
- Resulting array: [1, 2, 4, 5]

Input:
1. Size of the array (n)
2. n elements of the array
3. Position from which element needs to be deleted (valid index: 0 to n-1)

Output:
1. Original array
2. Array after deletion of element
3. Error message if position is invalid

Note: After deletion, the array size should decrease by 1, and all elements after the deleted position should be shifted left by one position.
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n, index;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index of the element to delete (0 to %d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) 
    {
        printf("Invalid index!\n");
    } 
    else 
    {
        for (int i = index; i < n - 1; i++) 
        {
            arr[i] = arr[i + 1];
        }

        printf("Array after deletion: ");
        for (int i = 0; i < (n - 1); i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
