/*
Question: Write a program to find the maximum and minimum elements in an array.

Description:
Create a program that takes an array of integers as input and finds the largest and smallest elements in the array.
For example:
- Array: [10, 5, 8, 12, 3]
  Maximum: 12
  Minimum: 3

Input:
1. Size of the array (n)
2. n elements of the array (entered separated by spaces)

Output:
1. Maximum element in the array
2. Minimum element in the array

Note: The program should work for both positive and negative numbers.
*/

#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of array to be created: ");
    scanf("%d", &size);
    getchar();
    
	int arr[size];
	int max, min;
	printf("\nEnter the array: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", arr+i);
	}
	
	max = arr[0];
	min = arr[0];
	
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		
		else if (arr[i] < min)
			min = arr[i];
	}
	
	printf("\nIn the given array --> Largest number = %d, and Smallest number = %d\n", max, min);
	
	return 0;
}