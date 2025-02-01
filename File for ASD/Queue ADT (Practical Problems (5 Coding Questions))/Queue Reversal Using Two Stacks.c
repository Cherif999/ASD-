#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1) return -1;
    int value = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return value;
}

int peek() {
    if (front == -1) return -1;
    return queue[front];
}

int is_empty() {
    return front == -1;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d dequeued from queue\n", dequeue());
    printf("Front element is %d\n", peek());
    return 0;
}
