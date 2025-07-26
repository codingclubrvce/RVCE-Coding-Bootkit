/*
Question: Write a recursive program to find the maximum element in an array.

Description:
Create a function that uses recursion to find and return the largest element in a given array of integers.
For example:
- Array: [3, 7, 2, 9, 5]
  Output: 9

Input:
1. An array of integers
2. The size of the array

Output:
1. The maximum element in the array

Note: The function should use recursion and not loops to find the maximum.
*/

int find_max(int arr[], int n, int i) {    // i = 0
    if (i == n - 1) {
        return arr[i];
    }
    
    int max_rest = find_max(arr, n, i + 1);
    return (arr[i] > max_rest) ? arr[i] : max_rest;
}