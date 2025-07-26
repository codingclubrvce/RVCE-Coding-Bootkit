/*
Question: Write a recursive program to calculate the factorial of a given number.

Description:
Create a function that uses recursion to calculate and return the factorial of a non-negative integer n. The factorial of n (n!) is the product of all positive integers less than or equal to n.
For example:
- Input: 5 → Output: 120 (5*4*3*2*1)
- Input: 0 → Output: 1 (by definition)

Input:
1. A non-negative integer n

Output:
1. The factorial of n

Note: The function should use recursion and not loops to calculate the factorial.
*/

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    return n * factorial(n - 1);
}