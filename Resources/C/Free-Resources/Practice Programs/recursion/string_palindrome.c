/*
Question: Write a recursive program to check if a given string is a palindrome.

Description:
Create a function that uses recursion to determine whether a string is a palindrome (reads the same forwards and backwards).
For example:
- Input: "madam" → Output: Palindrome
- Input: "hello" → Output: Not a palindrome

Input:
1. A string (array of characters)

Output:
1. Print or return whether the string is a palindrome or not

Note: The function should use recursion and not loops to check for palindrome.
*/

int is_palindrome(char s[], int start, int end) {   // start = 0, end = strlen(s) - 1
    if (start >= end) {
        return 1;
    }

    if (s[start] != s[end]) {
        return 0;
    }

    return is_palindrome(s, start + 1, end - 1);
}