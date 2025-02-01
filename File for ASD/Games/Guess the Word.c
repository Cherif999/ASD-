#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char words[][20] = {"apple", "banana", "cherry", "date", "elderberry"};
    srand(time(0));
    char *word = words[rand() % 5];
    int attempts = 3;
    char guess[20];

    while (attempts > 0) {
        printf("Guess the word: ");
        scanf("%s", guess);
        if (strcmp(guess, word) == 0) {
            printf("Congratulations! You guessed the word.\n");
            return 0;
        } else {
            attempts--;
            printf("Incorrect! Attempts left: %d\n", attempts);
        }
    }

    printf("You lost! The word was: %s\n", word);
    return 0;
}
