#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct node {
    int data;
    struct node *next;
} *top = NULL;

void main() {
    int ch, c;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");

    do {
        printf("\n\nEnter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\n\nContents of stack: ");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice.");
        }
        printf("\nDo you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &c);
    } while(c != 0);
}

void push() {
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\n\nEnter the number to be pushed into the stack: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("\n\nNumber pushed is %d", x);
}

void pop() {
    struct node *t;
    if(top == NULL)
        printf("\n\nStack Underflow");
    else {
        t = top;
        top = top->next;
        printf("\nDeleted element is %d", t->data);
        free(t);
    }
}

void display() {
    struct node *i;
    if(top == NULL)
        printf("\nStack is empty");
    else {
        for(i = top; i != NULL; i = i->next)
            printf("%d, ", i->data);
    }
}
