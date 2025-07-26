/*
Question: Write a recursive program to print numbers from n to 1.

Description:
Create a function that uses recursion to print all numbers from a given integer n down to 1, separated by spaces.
For example:
- Input: 5 → Output: 5 4 3 2 1

Input:
1. An integer n

Output:
1. Numbers from n to 1, separated by spaces

Note: The function should use recursion and not loops to print the numbers.
*/

void print_n_to_1(int n) {
    if (n == 0) {
        return;
    }

    printf("%d ", n);
    print_n_to_1(n - 1);
}