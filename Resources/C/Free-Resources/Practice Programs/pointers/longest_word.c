/*
Question: Write a program to find the longest word in a string using pointers.

Description:
Create a function that takes a string as input and uses pointers to find and return the longest word in the string. Words are separated by spaces.
For example:
- Input: "I love programming" → Output: "programming"
- Input: "C pointer example" → Output: "pointer"

Input:
1. A string (array of characters)

Output:
1. The longest word in the string

Note: Use pointer arithmetic to traverse the string and identify words.
*/

void longest_word(char *str, char *result) {
    int max_len = 0, curr_len = 0;
    char *start = str, *word_start = str;

    while (*str != '\0') {
        if (*str != ' ' && *str != '\0') {
            curr_len++;
        } 
        else {
            if (curr_len > max_len) {
                max_len = curr_len;
                word_start = str - curr_len;
            }
            curr_len = 0;
        }
        str++;
    }

    if (curr_len > max_len) {
        max_len = curr_len;
        word_start = str - curr_len;
    }

    for (int i = 0; i < max_len; i++) {
        result[i] = word_start[i];
    }
    result[max_len] = '\0';
}
