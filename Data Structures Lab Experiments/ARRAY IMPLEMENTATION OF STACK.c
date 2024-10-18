#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void push();
void pop();
void traverse();
int stack[MAXSIZE];
int top = -1;

int main() {
    int choice;
    while (1) {
        printf("\n1. PUSH ");
        printf("\n2. POP ");
        printf("\n3. TRAVERSE ");
        printf("\n4. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("\nYou entered an invalid choice.");
        }
    }
    return 0;
}

void push() {
    int item;
    if (top == MAXSIZE - 1) {
        printf("\nThe stack is full.");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
        printf("%d has been pushed onto the stack.", item);
    }
}

void pop() {
    if (top == -1) {
        printf("\nThe stack is empty.");
    } else {
        int item = stack[top];
        top = top - 1;
        printf("\nDeleted item is %d", item);
    }
}

void traverse() {
    if (top == -1) {
        printf("\nThe stack is empty.");
    } else {
        printf("\nStack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
    }
}
