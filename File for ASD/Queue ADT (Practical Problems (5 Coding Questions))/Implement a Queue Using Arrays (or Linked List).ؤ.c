#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int peek() {
    if (front == -1 || front > rear) return -1;
    return queue[front];
}

int is_empty() {
    return front == -1 || front > rear;
}

int is_full() {
    return rear == MAX - 1;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d dequeued from queue\n", dequeue());
    printf("Front element is %d\n", peek());
    return 0;
}
