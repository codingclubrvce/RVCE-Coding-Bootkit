# -----------------------------------------------------------------------------
# Rock-Paper-Scissors Game (Mini-Project)
#
# Description:
# This is a command-line implementation of the classic Rock-Paper-Scissors game.
# The user plays against the computer, entering moves ("rock", "paper", or "scissors")
# and can check scores or end the game at any time.
#
# Features:
# - Custom exception handling for invalid user inputs
# - Score tracking for both user and computer
# - Displays round results and final winner
# - User commands: "rock", "paper", "scissors", "score", "end"
#
# How to Play:
# 1. Run the program and enter 'start' to begin.
# 2. Enter your move ("rock", "paper", or "scissors") each round.
# 3. Enter "score" to view current scores.
# 4. Enter "end" to finish the game and see the final result.
#
# -----------------------------------------------------------------------------

import random

# Creating a custom exception to handle invalid user inputs
class InvalidUserInput(Exception):
    """Exception raised when the user enters a command that does not match the given keywords"""
    pass


# Defining a function to decide the winner of each round
def winner(user_input, computer_input):
    if user_input == computer_input:
        return None
    else:
        if user_input == "rock" and computer_input == "scissors":
            return "user"
        elif user_input == "scissors" and computer_input == "paper":
            return "user"
        elif user_input == "paper" and computer_input == "rock":
            return "user"
        else:
            return "computer"


outcomes = ("rock", "paper", "scissors")
user_commands = {"rock", "paper", "scissors", "score", "end"}
round_number = 0

# Initialising Scores
user_score = 0
computer_score = 0

# Initial Output Screen
print("Welcome to the game of Rock-Paper-Scissors! \n")
print("User Commands (Case Insensitive): \n"
      "    1. Rock or Paper or Scissors --> possible moves \n"
      "    2. Score --> to display the current scores \n"
      "    3. End --> to terminate the game \n")


# Taking user input to start the game
start_command = input("Enter 'start' to begin the game: ").strip().lower()

# Begins the game only upon entering a successful start command
if start_command == "start":
    while True:
        user_command = input("\nEnter a command: ").strip().lower()
        if user_command != "end":
            try:
                if user_command in outcomes:
                    round_number += 1
                    user_move = user_command
                    print(f"\nRound {round_number}: ")

                    print(f"\t\tYour move --> {user_move}")
                    computer_move = random.choice(outcomes)         # Generating a random choice for computer move

                    print(f"\t\tComputer generated move --> {computer_move}")

                    round_winner = winner(user_move, computer_move)
                    if round_winner == "user":
                        print("\t\tYou won!")
                        user_score += 1
                    elif round_winner == "computer":
                        print("\t\tYou lost!")
                        computer_score += 1
                    else:
                        print("\t\tTie!")

                elif user_command == "score":
                    print(f"The current scores are: User = {user_score} and Computer = {computer_score}")
                else:
                    raise InvalidUserInput

            except InvalidUserInput:
                print("Invalid user command! Please try again.")

        else:
            print(f"The final scores are: User = {user_score} and Computer = {computer_score}")
            if user_score > computer_score:
                print("\nCongratulations! You won the game.")
            elif computer_score > user_score:
                print("\nBetter luck next time! You lost the game.")
            else:
                print("\nNo winner! It's a draw.")
            break


else:
    print("Invalid command! Please restart the game.")