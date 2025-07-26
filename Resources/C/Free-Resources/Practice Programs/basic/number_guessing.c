/*
Question: Write a program to implement a simple random number guessing game.

Description:
Create a program that generates a random number within a specified range and asks the user to guess the number. The program should give feedback if the guess is too high or too low, and continue until the user guesses correctly.
For example:
- Random number: 7
- User guesses: 5 (too low), 9 (too high), 7 (correct)

Input:
1. User guesses (repeatedly until correct)

Output:
1. Feedback for each guess ("Too high", "Too low", or "Correct!")
2. Number of attempts taken to guess correctly

Note: Use the random number generator to select the target number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(0));
    
    int secretNumber = (rand() % 100) + 1;
    int guess;
    int attempts = 0; // To count the number of attempts

    do 
    {
        printf("Enter your guess:  ");
        scanf("%d", &guess);
        attempts++; // Incrementing the attempt counter

        if (guess > secretNumber) 
        {
            printf("Too high!\n");
        } 
        else if (guess < secretNumber) 
        {
            printf("Too low!\n");
        } 
        else 
        {
            printf("You successfully guessed it in %d attempts!\n", attempts);
        }

    } 
    while (guess != secretNumber);

    return 0;
}
