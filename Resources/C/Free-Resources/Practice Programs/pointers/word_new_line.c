/*
Question: Write a program to print each word of a string on a new line using pointers.

Description:
Create a function that takes a string as input and uses pointers to print each word on a separate line.

Input:
1. A string (array of characters)

Output:
1. Each word printed on a new line

Note: Use pointer arithmetic to identify word boundaries and print accordingly.
*/

void print_on_new_line(char* str) {
    while (*str != '\0') {
        if (*str == ' ') {
            printf("\n");
        }
        else {
            printf("%c", *str);
        }
        str++;
    }
}
