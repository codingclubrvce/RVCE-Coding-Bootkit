/*
Question: Write a recursive program to implement binary search on a sorted array.

Description:
Create a function that uses recursion to search for a target value in a sorted array using the binary search algorithm. Return the index of the target if found, or -1 if not found.
For example:
- Array: [1, 3, 5, 7, 9], Target: 7 → Output: 3
- Array: [2, 4, 6, 8], Target: 5 → Output: -1

Input:
1. A sorted array of integers
2. The size of the array
3. The target value to search for

Output:
1. The index of the target value if found, or -1 if not found

Note: The function should use recursion and not loops to perform the search.
*/

int binary_search(int arr[], int target, int left, int right) {    // left = 0, right = n - 1, n = length of arr
    if (left > right) {
        return -1;
    }

    int middle = (left + right) / 2;

    if (arr[middle] == target) {
        return middle;
    }

    else if (target < arr[middle]) {
        return binary_search(arr, target, left, middle - 1);
    }

    return binary_search(arr, target, middle + 1, right);
}
