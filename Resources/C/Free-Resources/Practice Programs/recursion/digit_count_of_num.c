/*
Question: Write a recursive program to count the number of digits in a given number.

Description:
Create a function that uses recursion to count and return the number of digits in an integer.
For example:
- Input: 12345 → Output: 5
- Input: 7 → Output: 1

Input:
1. An integer number

Output:
1. The number of digits in the given number

Note: The function should use recursion and not loops to count the digits.
*/

int count_digits(int n) {
    if (n == 0) {
        return 1;
    }

    return 1 + count_digits(n / 10);
}