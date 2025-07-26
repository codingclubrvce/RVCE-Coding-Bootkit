/*
Question: Write a recursive program to calculate the power of a number (a^b).

Description:
Create a function that uses recursion to calculate and return the value of a raised to the power of b (a^b), where a and b are integers.
For example:
- Input: a = 2, b = 5 → Output: 32 (2^5)
- Input: a = 3, b = 3 → Output: 27 (3^3)

Input:
1. Base integer a
2. Exponent integer b (non-negative)

Output:
1. The value of a raised to the power of b

Note: The function should use recursion and not loops to calculate the power.
*/

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    
    return a * power(a, b - 1);
}