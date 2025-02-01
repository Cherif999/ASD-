#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int numbers[10];
    for (int i = 0; i < 10; i++) numbers[i] = rand() % 100;
    int sorted[10];
    for (int i = 0; i < 10; i++) sorted[i] = numbers[i];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    int user[10];
    printf("Sort these numbers in ascending order:\n");
    for (int i = 0; i < 10; i++) printf("%d ", numbers[i]);
    printf("\nEnter your sorted list (space-separated): ");
    for (int i = 0; i < 10; i++) scanf("%d", &user[i]);
    int correct = 0;
    for (int i = 0; i < 10; i++) {
        if (user[i] == sorted[i]) correct++;
    }
    printf("Correctly placed numbers: %d\n", correct);
    printf("Incorrectly placed numbers: %d\n", 10 - correct);
    return 0;
}
