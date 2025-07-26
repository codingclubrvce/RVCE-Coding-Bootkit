/*
Question: Write a program to find the frequency of a given character in a string using pointers.

Description:
Create a function that takes a string and a character as input, and uses pointers to count how many times the character appears in the string.
For example:
- Input: str = "hello world", ch = 'l' → Output: 3
- Input: str = "pointer", ch = 't' → Output: 1

Input:
1. A string (array of characters)
2. A character to search for

Output:
1. The frequency (count) of the character in the string

Note: Use pointer arithmetic to traverse the string.
*/

int char_frequency(char *str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}
