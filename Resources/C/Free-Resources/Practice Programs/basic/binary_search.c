/*
Question: Write a program to implement Binary Search algorithm.

Description:
Implement binary search algorithm to find a target element in a sorted array.
Binary search works by repeatedly dividing the search range in half.
For example:
- Array: [1, 3, 5, 7, 9, 11, 13, 15]
- Target: 7
- Steps: Check middle element (9)
         Search left half [1,3,5,7]
         Check middle element (3)
         Search right half [5,7]
         Find 7

Input:
1. Size of the array (n)
2. n elements in sorted order
3. Target element to search

Output:
1. Position of the target element if found
2. Message "Element not found" if target doesn't exist in array

Note: Array must be sorted in ascending order for binary search to work
*/

#include <stdio.h>

int main()
{
	int n, arr[100];
	int target;
	int found = 0;
	
	printf("Enter the number of elements in the array:  ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("Enter the target value:  ");
	scanf("%d", &target);
	
	if (target < arr[0] || target > arr[n - 1])
	{
		printf("%d is not present in the array\n", target);
		return 0;
	}
	
	int left = 0, middle = n/2, right = n - 1;
	
	while (found == 0)
	{	
		if (target == arr[middle])
		{
			printf("%d is present in the array\n", target);
			return 0;
		}
		
		else if (target < arr[middle])
		{
			right = middle - 1;
		}
		
		else
		{
			left = middle + 1;
		}
		
		middle = (right + left) / 2;
	}
	
	printf("%d is not present in the array\n", target);
	return 0;
}
