/*
Question: Write a program to demonstrate the working of for, while, and do-while loops in C.

Description:
Create a program that prints numbers from 1 to 5 using three different types of loops: for, while, and do-while. Show the output of each loop separately.
For example:
- Output:
  Using for loop:
  1 2 3 4 5
  Using while loop:
  1 2 3 4 5
  Using do-while loop:
  1 2 3 4 5

Input:
(No input required for this demonstration)

Output:
1. Numbers from 1 to 5 printed using each loop type, with clear section headers

Note: This program is for demonstration and learning purposes.
*/

#include <stdio.h>

int main() {
    int i;

    printf("Using for loop:\n");
    for (i = 1; i <= 5; i++) 
	{
        printf("%d ", i);
    }
    printf("\n");

    printf("Using while loop:\n");
    i = 1;
    while (i <= 5) 
	{
        printf("%d ", i);
        i++;
    }
    printf("\n");

    printf("Using do-while loop:\n");
    i = 1;
    do 
	{
        printf("%d ", i);
        i++;
    } 
	while (i <= 5);
    printf("\n");

    return 0;
}
