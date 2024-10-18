#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void insert(int);
void delete();
void display();

void main() {
    int choice, value, q;
    printf("\n:: Queue Implementation using Linked List ::\n");
    do {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection! Please try again.\n");
        }
        printf("Do you want to continue (1 for Yes / 0 for No): ");
        scanf("%d", &q);
    } while(q != 0);
}

void insert(int value) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInsertion is successful!\n");
}

void delete() {
    if(front == NULL) {
        printf("\nQueue is empty!\n");
    } else {
        struct Node *temp = front;
        front = front->next;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
        if(front == NULL) {
            rear = NULL;
        }
    }
}

void display() {
    if(front == NULL) {
        printf("\nQueue is empty!\n");
    } else {
        struct Node *temp = front;
        while(temp != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
