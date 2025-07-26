/*
Question: Write a recursive program to find the GCD (Greatest Common Divisor) of two numbers using Euclid's algorithm.

Description:
Create a function that uses recursion and Euclid's algorithm to find the greatest common divisor (GCD) of two integers.
For example:
- Input: 48, 18 → Output: 6
- Input: 56, 98 → Output: 14

Input:
1. Two integers

Output:
1. The GCD of the two numbers

Note: The function should use recursion and not loops to calculate the GCD.
*/

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}