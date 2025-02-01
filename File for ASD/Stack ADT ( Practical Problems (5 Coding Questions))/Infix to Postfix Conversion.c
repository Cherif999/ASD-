#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) postfix[j++] = infix[i];
        else if (infix[i] == '(') push(infix[i]);
        else if (infix[i] == ')') {
            while (stack[top] != '(') postfix[j++] = pop();
            pop();
        } else {
            while (precedence(stack[top]) >= precedence(infix[i])) postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }
    while (!is_empty()) postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
