#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5
int front = -1, rear = -1, choice;
int q[MAXSIZE];

void del();
void display();
void ins();

void main() {
    while(1) {
        printf("\n1 --> Insert\n");
        printf("2 --> Delete\n");
        printf("3 --> Display\n");
        printf("4 --> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                ins();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
        getch();
    }
}

void ins() {
    int num;
    if(rear == (MAXSIZE - 1)) {
        printf("Queue is full\n");
    } else {
        printf("Enter the number: ");
        scanf("%d", &num);
        rear = rear + 1;
        q[rear] = num;
        if(front == -1)
            front = 0;
    }
}

void del() {
    if(front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted item = %d\n", q[front]);
        if(front == rear) {
            front = rear = -1;  // Reset when the last element is deleted
        } else {
            front = front + 1;
        }
    }
}

void display() {
    int i;
    if(front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\nThe status of the queue:\n");
        for(i = front; i <= rear; i++) {
            printf("%d\n", q[i]);
        }
    }
}
