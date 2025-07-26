/*
Question: Write a recursive program to find the sum of digits of a given number.

Description:
Create a function that uses recursion to calculate and return the sum of all digits in an integer.
For example:
- Input: 1234 → Output: 10 (1+2+3+4)
- Input: 56 → Output: 11 (5+6)

Input:
1. An integer number

Output:
1. The sum of the digits of the given number

Note: The function should use recursion and not loops to calculate the sum.
*/

int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    
    return (n % 10) + sum_of_digits(n / 10);
}