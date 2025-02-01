#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    if (top >= MAX - 1) return;
    stack[++top] = value;
}

char pop() {
    if (top < 0) return '\0';
    return stack[top--];
}

int is_empty() {
    return top == -1;
}

int is_balanced(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') push(expr[i]);
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char popped = pop();
            if ((expr[i] == ')' && popped != '(') ||
                (expr[i] == '}' && popped != '{') ||
                (expr[i] == ']' && popped != '[')) return 0;
        }
    }
    return is_empty();
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);
    if (is_balanced(expr)) printf("Balanced\n");
    else printf("Unbalanced\n");
    return 0;
}
