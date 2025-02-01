#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int count[MAX] = {0};
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int value) {
    queue[++rear] = value;
}

int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

void first_non_repeating(char *stream) {
    for (int i = 0; stream[i] != '\0'; i++) {
        count[stream[i]]++;
        enqueue(stream[i]);
        while (front <= rear) {
            if (count[queue[front]] == 1) {
                printf("First non-repeating character: %c\n", queue[front]);
                break;
            }
            dequeue();
        }
        if (front > rear) printf("No non-repeating character\n");
    }
}

int main() {
    char stream[] = "aabbcdde";
    first_non_repeating(stream);
    return 0;
}
