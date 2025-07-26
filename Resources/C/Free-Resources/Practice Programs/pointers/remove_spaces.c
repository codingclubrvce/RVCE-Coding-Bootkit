/*
Question: Write a program to remove all spaces from a string using pointers.

Description:
Create a function that takes a string as input and uses pointers to remove all spaces from the string.

Input:
1. A string (array of characters)

Output:
1. The modified string with all spaces removed

Note: Use pointer arithmetic to traverse and modify the string.
*/

void remove_spaces(char *str) {
    char *read = str;
    char *write = str;

    while (*read != '\0') {
        if (*read != ' ') {
            *write = *read;
            write++;
        }
        read++;
    }

    *write = '\0';
}
