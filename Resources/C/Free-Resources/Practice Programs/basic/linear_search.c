/*
Question: Write a program to implement linear search algorithm on an array.

Description:
Create a program that searches for a target value in an array by checking each element one by one (linear search).
For example:
- Array: [4, 2, 7, 1, 9], Target: 7 → Output: Found at position 3
- Array: [5, 8, 6], Target: 2 → Output: Not found

Input:
1. Size of the array (n)
2. n elements of the array
3. Target value to search for

Output:
1. Position (index) of the target value if found (1-based or 0-based as per your code)
2. Message if the target value is not found

Note: The program should work for both positive and negative integers.
*/

#include <stdio.h>

int main()
{
	int size;
    printf("Enter the size of array to be created: ");
    scanf("%d", &size);
    getchar();
    
	int arr[size];
	printf("\nEnter the array: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", arr+i);
	}
	getchar();
	
	int key;
	printf("\nEnter the number to be searched: ");
	scanf("%d", &key);
	
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			printf("\n%d is present in the array\n", key);
			return 0;
		}
	}
	
	printf("\n%d is not present in the array\n", key);
	
	return 0;
}