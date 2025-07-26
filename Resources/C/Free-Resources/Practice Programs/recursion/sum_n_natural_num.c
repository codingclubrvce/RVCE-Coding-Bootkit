/*
Question: Write a recursive program to find the sum of the first n natural numbers.

Description:
Create a function that uses recursion to calculate and return the sum of the first n natural numbers (1 + 2 + ... + n).
For example:
- Input: 5 → Output: 15 (1+2+3+4+5)
- Input: 10 → Output: 55 (1+2+...+10)

Input:
1. A non-negative integer n

Output:
1. The sum of the first n natural numbers

Note: The function should use recursion and not loops to calculate the sum.
*/

int sum_natural(int n) {
    if (n == 0) {
        return 0;
    }
    
    return n + sum_natural(n - 1);
}