#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

int evaluate_postfix(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) push(expr[i] - '0');
        else {
            int op2 = pop();
            int op1 = pop();
            if (expr[i] == '+') push(op1 + op2);
            else if (expr[i] == '-') push(op1 - op2);
            else if (expr[i] == '*') push(op1 * op2);
            else if (expr[i] == '/') push(op1 / op2);
        }
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", expr);
    printf("Result: %d\n", evaluate_postfix(expr));
    return 0;
}
