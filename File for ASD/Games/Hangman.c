#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char words[][20] = {"programming", "computer", "algorithm", "language", "developer"};
    srand(time(0));
    char *word = words[rand() % 5];
    int len = strlen(word);
    char guessed[20];
    for (int i = 0; i < len; i++) guessed[i] = '_';
    guessed[len] = '\0';
    int attempts = 6;
    char guess;
    int correct;

    while (attempts > 0 && strcmp(guessed, word) != 0) {
        printf("Word: %s\n", guessed);
        printf("Attempts left: %d\n", attempts);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        correct = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = 1;
            }
        }
        if (!correct) attempts--;
    }

    if (strcmp(guessed, word) == 0) printf("Congratulations! You guessed the word: %s\n", word);
    else printf("You lost! The word was: %s\n", word);

    return 0;
}
