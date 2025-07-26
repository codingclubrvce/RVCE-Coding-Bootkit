/*
Question: Write a program to convert all lowercase letters in a string to uppercase using pointers.

Description:
Create a function that takes a string as input and uses pointers to convert all lowercase alphabetic characters to uppercase in place.
For example:
- Input: "Hello World" → Output: "HELLO WORLD"
- Input: "pointer" → Output: "POINTER"

Input:
1. A string (array of characters)

Output:
1. The modified string with all lowercase letters converted to uppercase

Note: Use pointer arithmetic to traverse and modify the string in place.
*/

void to_uppercase(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}
