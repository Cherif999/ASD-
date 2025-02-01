#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) return;
    stack[++top] = value;
}

int pop() {
    if (top < 0) return -1;
    return stack[top--];
}

int peek() {
    if (top < 0) return -1;
    return stack[top];
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX - 1;
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("%d popped from stack\n", pop());
    printf("Top element is %d\n", peek());
    return 0;
}
