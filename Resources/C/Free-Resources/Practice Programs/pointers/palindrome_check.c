/*
Question: Write a program to check if a string is a palindrome using pointers.

Description:
Create a function that takes a string as input and uses pointers to check if the string is a palindrome (reads the same forwards and backwards).
For example:
- Input: "level" → Output: Palindrome
- Input: "hello" → Output: Not a palindrome

Input:
1. A string (array of characters)

Output:
1. 1 if the string is a palindrome, 0 otherwise

Note: Use pointer arithmetic to compare characters from both ends of the string.
*/

int is_palindrome(char *str) {
    char *start = str;
    char *end = str;

    while (*(end + 1) != '\0') {
        end++;
    }

    while (start < end) {
        if (*start != *end) {
            return 0; 
        }
        start++;
        end--;
    }

    return 1; 
}
