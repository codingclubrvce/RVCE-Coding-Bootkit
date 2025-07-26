/*
Question: Write a recursive program to reverse a given string in place.

Description:
Create a function that uses recursion to reverse the characters of a string in place (without using extra arrays).
For example:
- Input: "hello" → Output: "olleh"
- Input: "recursion" → Output: "noisrucer"

Input:
1. A string (array of characters)

Output:
1. The reversed string (in place)

Note: The function should use recursion and not loops to reverse the string.
*/

void reverse_string(char *s, int start, int end) {  // start = 0, end = strlen(s) - 1
    if (start >= end) {
        return;
    }

    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    reverse_string(s, start + 1, end - 1);
}
