/*
Question: Write a recursive program to check if a given number is prime.

Description:
Create a function that uses recursion to determine whether a given integer n is a prime number. A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.
For example:
- Input: 7 → Output: Prime
- Input: 10 → Output: Not prime

Input:
1. An integer number n

Output:
1. 1 if the number is prime, 0 otherwise

Note: The function should use recursion and not loops to check for primality.
*/

int is_prime(int n, int i) {    // i = 2
    if (n <= 2) {
        return (n == 2);
    }

    if (n % i == 0) {
        return 0;
    }

    if (i * i > n) {
        return 1;
    }

    return is_prime(n, i + 1);
}