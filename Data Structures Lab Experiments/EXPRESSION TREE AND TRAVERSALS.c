#include <stdio.h>
#include <stdlib.h>

#define operand(x) (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')

typedef struct node *tree;

struct node {
    char data;
    tree left, right;
};

tree stack[20];
int top = -1;
char post[20];
tree T = NULL;

void push(tree a) {
    if (top >= 19) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = a;
}

tree pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

void conversion() {
    int i;
    tree a, b, c;
    char x;
    for (i = 0; (x = post[i]) != '\0'; i++) {
        if (operand(x)) {
            a = (tree)malloc(sizeof(struct node));
            a->data = x;
            a->left = a->right = NULL;
            push(a);
        } else {
            a = pop();
            b = pop();
            c = (tree)malloc(sizeof(struct node));
            c->data = x;
            c->right = a;
            c->left = b;
            push(c);
        }
    }
    T = pop(); // Assign the last popped tree to T
}

void postfix(tree a) {
    if (a != NULL) {
        postfix(a->left);
        postfix(a->right);
        printf("%c ", a->data);
    }
}

void infix(tree a) {
    if (a != NULL) {
        infix(a->left);
        printf("%c ", a->data);
        infix(a->right);
    }
}

void prefix(tree a) {
    if (a != NULL) {
        printf("%c ", a->data);
        prefix(a->left);
        prefix(a->right);
    }
}

int main() {
    printf("Enter postfix expression: ");
    scanf("%s", post);
    conversion();

    printf("\nPostfix expression is: ");
    postfix(T);
    
    printf("\nInfix expression is: ");
    infix(T);
    
    printf("\nPrefix expression is: ");
    prefix(T);
    
    return 0;
}
