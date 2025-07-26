/*
Question: Write a recursive program to check if an array is sorted in ascending order.

Description:
Create a function that uses recursion to determine whether the elements of a given array are sorted in ascending order.
For example:
- Array: [1, 2, 3, 4, 5] → Output: Sorted
- Array: [1, 3, 2, 4] → Output: Not sorted

Input:
1. An array of integers
2. The size of the array

Output:
1. 1 if the array is sorted in ascending order, 0 otherwise

Note: The function should use recursion and not loops to check the order.
*/

int is_sorted(int arr[], int n, int i) {    // i = 0
    if (i >= n - 1) {
        return 1;
    }

    if (arr[i] > arr[i + 1]) {
        return 0;
    }

    return is_sorted(arr, n, i + 1);
}