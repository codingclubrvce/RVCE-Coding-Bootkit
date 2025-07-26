/*
Question: Write a recursive program to find the nth term of the Fibonacci sequence.

Description:
Create a function that uses recursion to return the nth term of the Fibonacci sequence. The Fibonacci sequence is defined as:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1
For example:
- Input: 5 → Output: 5 (sequence: 0, 1, 1, 2, 3, 5)
- Input: 7 → Output: 13

Input:
1. A non-negative integer n

Output:
1. The nth term of the Fibonacci sequence

Note: The function should use recursion and not loops to calculate the term.
*/

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    else if (n == 1) {
        return 1;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}