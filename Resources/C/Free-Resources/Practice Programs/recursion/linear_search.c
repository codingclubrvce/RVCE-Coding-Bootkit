/*
Question: Write a recursive program to implement linear search in an array.

Description:
Create a function that uses recursion to search for a target value in an array by checking each element one by one (linear search). Return the index of the target if found, or -1 if not found.
For example:
- Array: [4, 2, 7, 1, 9], Target: 7 → Output: 2
- Array: [5, 8, 6], Target: 2 → Output: -1

Input:
1. An array of integers
2. The size of the array
3. The target value to search for

Output:
1. The index of the target value if found, or -1 if not found

Note: The function should use recursion and not loops to perform the search.
*/

int linear_search(int arr[], int n, int key, int i) {   // i = 0
    if (i == n) {
        return -1;
    }

    if (arr[i] == key) {
        return i;
    }
    
    return linear_search(arr, n, key, i + 1);
}