/*
Question: Write a program to count the number of vowels in a string using pointers.

Description:
Create a function that takes a string as input and uses pointers to count the number of vowels (a, e, i, o, u) in the string.

Input:
1. A string (array of characters)

Output:
1. The count of vowels in the string

Note: Use pointer arithmetic to traverse the string and check for vowels.
*/

int count_vowels(char *str) {
    int count = 0;
    while (*str != '\0') {
        char ch = *str;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
        str++;
    }
    return count;
}