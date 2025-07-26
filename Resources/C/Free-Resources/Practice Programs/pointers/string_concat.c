/*
Question: Write a program to concatenate two strings using pointers.

Description:
Create a function that takes two strings as input and uses pointers to concatenate the second string to the end of the first string.

Input:
1. Destination string (array of characters)
2. Source string (array of characters)

Output:
1. The concatenated string

Note: Use pointer arithmetic to append characters from the source to the destination string.
*/

void concat_strings(char *dest, char *src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
