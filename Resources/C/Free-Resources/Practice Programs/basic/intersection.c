/*
Question: Write a program to find the intersection of two arrays.

Description:
Create a program that takes two arrays as input and prints the elements that are present in both arrays (intersection).
For example:
- Array 1: [1, 2, 3, 4, 5]
- Array 2: [3, 4, 5, 6, 7]
  Intersection: [3, 4, 5]

Input:
1. Size of the first array (n1) and its elements
2. Size of the second array (n2) and its elements

Output:
1. Elements that are present in both arrays (intersection)

Note: Do not print duplicate elements in the intersection.
*/

#include <stdio.h>

int main()
{
    int size1;
    printf("Enter the size of 1st array to be created: ");
    scanf("%d", &size1);
    getchar();
    
	int arr1[size1];
	printf("\nEnter the array: ");
	for (int i = 0; i < size1; i++)
	{
		scanf("%d", arr1+i);
	}
	getchar();
	
	int size2;
    printf("Enter the size of 2nd array to be created: ");
    scanf("%d", &size2);
    getchar();
    
	int arr2[size2];
	printf("\nEnter the array: ");
	for (int i = 0; i < size2; i++)
	{
		scanf("%d", arr2+i);
	}
	getchar();
	
	for (int i = 0; i < size1; i++)
	{
	    for (int j = 0; j < size2; j++)
	    {
	        if (arr1[i] == arr2[j])
	        {
	            printf("%d ", arr1[i]);
	            break;
	        }
	    }
	}
	
	return 0;
}