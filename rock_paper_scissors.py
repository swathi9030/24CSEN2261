import random

def get_computer_choice():
    return random.choice(['Rock', 'Paper', 'Scissors'])

def determine_winner(user_choice, computer_choice):
    if user_choice == computer_choice:
        return "It's a draw!"
    elif (user_choice == 'Rock' and computer_choice == 'Scissors') or \
         (user_choice == 'Paper' and computer_choice == 'Rock') or \
         (user_choice == 'Scissors' and computer_choice == 'Paper'):
        return "You win!"
    else:
        return "Computer wins!"

def main():
    print("Rock, Paper, Scissors Game!")

    user_choice = input("Enter your choice (Rock, Paper, Scissors): ").capitalize()

    if user_choice not in ['Rock', 'Paper', 'Scissors']:
        print("Invalid choice! Please enter Rock, Paper, or Scissors.")
        return 

    computer_choice = get_computer_choice()

    print(f"Your choice: {user_choice}")
    print(f"Computer's choice: {computer_choice}")

    result = determine_winner(user_choice, computer_choice)
    print(result)

if __name__ == "__main__":
    main()



OTUPUT :
Rock, Paper, Scissors Game!
Enter your choice (Rock, Paper, Scissors): paper
Your choice: Paper
Computer's choice: Paper
It's a draw!
