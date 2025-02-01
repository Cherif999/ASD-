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

int is_empty() {
    return top == -1;
}

void insert_at_bottom(int value) {
    if (is_empty()) push(value);
    else {
        int temp = pop();
        insert_at_bottom(value);
        push(temp);
    }
}

void reverse_stack() {
    if (!is_empty()) {
        int temp = pop();
        reverse_stack();
        insert_at_bottom(temp);
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    reverse_stack();
    while (!is_empty()) printf("%d ", pop());
    return 0;
}
