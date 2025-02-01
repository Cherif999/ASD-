#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void number_guessing_game() {
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess > number)
            printf("Too high!\n");
        else if (guess < number)
            printf("Too low!\n");
        else
            printf("Correct! Attempts: %d\n", attempts);
    } while (guess != number);
}

void rock_paper_scissors() {
    char *choices[] = {"rock", "paper", "scissors"};
    char user_choice[10];
    int computer_choice;
    srand(time(0));
    while (1) {
        printf("Enter rock, paper, or scissors (or 'exit' to quit): ");
        scanf("%s", user_choice);
        if (strcmp(user_choice, "exit") == 0)
            break;
        computer_choice = rand() % 3;
        printf("Computer chose: %s\n", choices[computer_choice]);
        if (strcmp(user_choice, choices[computer_choice]) == 0)
            printf("It's a tie!\n");
        else if ((strcmp(user_choice, "rock") == 0 && computer_choice == 2) ||
                 (strcmp(user_choice, "paper") == 0 && computer_choice == 0) ||
                 (strcmp(user_choice, "scissors") == 0 && computer_choice == 1))
            printf("You win!\n");
        else
            printf("You lose!\n");
    }
}

int main() {
    rock_paper_scissors();
    return 0;
}
