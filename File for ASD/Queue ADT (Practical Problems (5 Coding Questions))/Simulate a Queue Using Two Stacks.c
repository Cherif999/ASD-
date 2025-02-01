#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) return;
    stack[++(*top)] = value;
}

int pop(int stack[], int *top) {
    if (*top == -1) return -1;
    return stack[(*top)--];
}

void reverse_queue(int queue[], int *front, int *rear) {
    while (*front != -1 && *front <= *rear) push(stack1, &top1, queue[(*front)++]);
    while (top1 != -1) push(stack2, &top2, pop(stack1, &top1));
    *front = 0;
    *rear = -1;
    while (top2 != -1) queue[++(*rear)] = pop(stack2, &top2);
}

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    enqueue(queue, &rear, 10);
    enqueue(queue, &rear, 20);
    enqueue(queue, &rear, 30);
    reverse_queue(queue, &front, &rear);
    while (front <= rear) printf("%d ", queue[front++]);
    return 0;
}
