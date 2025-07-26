/*
Question: Write a program to replace all occurrences of a given character in a string with another character using pointers.

Description:
Create a function that takes a string and two characters as input, and uses pointers to replace every occurrence of the first character with the second character in the string.
For example:
- Input: str = "banana", old = 'a', new = 'o' → Output: "bonono"
- Input: str = "hello", old = 'l', new = 'x' → Output: "hexxo"

Input:
1. A string (array of characters)
2. The character to be replaced
3. The new character to replace with

Output:
1. The modified string after replacement

Note: Use pointer arithmetic to traverse and modify the string in place.
*/

void replace_char(char *str, char old, char new) {
    while (*str != '\0') {
        if (*str == old) {
            *str = new;
        }
        str++;
    }
}
