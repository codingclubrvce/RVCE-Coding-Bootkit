/*
Question: Write a program to check whether a given character is a vowel or a consonant.

Description:
Create a program that takes a single alphabet character as input and determines whether it is a vowel (a, e, i, o, u) or a consonant.
For example:
- Input: a → Output: Vowel
- Input: b → Output: Consonant
- Input: E → Output: Vowel

Input:
1. A single alphabet character (uppercase or lowercase)

Output:
1. Print whether the character is a vowel or a consonant

Note: The program should handle both uppercase and lowercase letters and display an error for non-alphabetic input.
*/

#include <stdio.h>

int main()
{
    char letter;

    printf("Enter an alphabet:  ");
    scanf("%c", &letter);

    switch (letter)
    {
        case 'a':
        {
            printf("\n%c is a vowel\n");
            break;
        }
    
        case 'e':
        {
            printf("\n%c is a vowel\n");
            break;
        }

        case 'i':
        {
            printf("\n%c is a vowel\n");
            break;
        }

        case 'o':
        {
            printf("\n%c is a vowel\n");
            break;
        }

        case 'u':
        {
            printf("\n%c is a vowel\n");
            break;
        }

        default:
        {
            printf("\n%c is a consonant\n");
            break;
        }
    }

    return 0;
}