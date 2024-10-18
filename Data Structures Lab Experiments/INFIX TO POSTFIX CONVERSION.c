#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define operand(x) (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')

char infix[MAX], stack[MAX], postfix[MAX];
int top = -1;

void push(char n) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = n;
}

int priority(char x) {
    return (x == '*' || x == '/') ? 2 : (x == '+' || x == '-') ? 1 : -1;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0'; // Return null character on underflow
    }
    return stack[top--];
}

void infixtopostfix() {
    int j, l = 0;
    char x, y;
    for (j = 0; (x = infix[j]) != '\0'; j++) {
        if (operand(x)) {
            postfix[l++] = x;
        } else if (x == '(') {
            push(x);
        } else if (x == ')') {
            while (top != -1 && (y = pop()) != '(') {
                postfix[l++] = y;
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priority(x)) {
                postfix[l++] = pop();
            }
            push(x);
        }
    }
    while (top != -1) {
        postfix[l++] = pop();
    }
    postfix[l] = '\0'; // Null-terminate the postfix string
}

int main() {
    printf("Enter the Infix expression: ");
    scanf("%s", infix);
    infixtopostfix();
    printf("The Postfix Expression is: %s\n", postfix);
    return 0;
}
