/*
Question: Write a recursive program to print numbers from 1 to n.

Description:
Create a function that uses recursion to print all numbers from 1 up to a given integer n, separated by spaces.
For example:
- Input: 5 → Output: 1 2 3 4 5

Input:
1. An integer n

Output:
1. Numbers from 1 to n, separated by spaces

Note: The function should use recursion and not loops to print the numbers.
*/

void print_1_to_n(int n, int i) {   // i = 1
    if (i > n) {
        return;
    }

    printf("%d ", i);
    print_1_to_n(n, i + 1);
}