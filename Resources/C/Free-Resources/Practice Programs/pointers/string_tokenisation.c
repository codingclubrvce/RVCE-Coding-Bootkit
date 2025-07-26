/*
Question: Write a program to tokenize a string into words using pointers.

Description:
Create a function that takes a string as input and uses pointers to split the string into words (tokens) separated by spaces.

Input:
1. A string (array of characters)

Output:
1. Each word (token) printed or stored separately

Note: Use pointer arithmetic to identify and extract words from the string.
*/

void tokenize(char *str, char delim) {
    while (*str != '\0') {
        if (*str == delim) {
            printf("\n");
        } 
        else {
            printf("%c", *str);
        }
        str++;
    }
}
