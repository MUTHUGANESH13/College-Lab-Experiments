#include <stdio.h>
#include <stdlib.h>
#define qsize 6

int queue[qsize];
int front = -1, rear = -1;

void create() {
    int n;
    printf("Enter the number of elements (max %d): ", qsize);
    scanf("%d", &n);
    if (n > qsize) {
        printf("Cannot insert more than %d elements.\n", qsize);
        return;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    front = 0;
    rear = n - 1;
}

void isfull() {
    if ((rear + 1) % qsize == front) {
        printf("The queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
}

void isempty() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}

void enqueue() {
    int x;
    printf("Enter the number to be inserted: ");
    scanf("%d", &x);
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = x;
    } else if ((rear + 1) % qsize == front) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % qsize;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue underflows\n");
    } else {
        int ele = queue[front];
        printf("Deleted element: %d\n", ele);
        if (front == rear) { // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % qsize;
        }
    }
}

void display_front() {
    if (front != -1) {
        printf("Front: %d\n", queue[front]);
    } else {
        printf("Queue is empty\n");
    }
}

void display_rear() {
    if (rear != -1) {
        printf("Rear: %d\n", queue[rear]);
    } else {
        printf("Queue is empty\n");
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % qsize;
    }
    printf("\n");
}

int main() {
    int ch, c;
    create();
    do {
        printf("What operation do you want to perform?\n");
        printf("1. Is full?\n2. Is empty\n3. Enqueue\n4. Dequeue\n");
        printf("5. Display rear\n6. Display front\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                isfull();
                break;
            case 2:
                isempty();
                break;
            case 3:
                enqueue();
                display();
                break;
            case 4:
                dequeue();
                display();
                break;
            case 5:
                display_rear();
                break;
            case 6:
                display_front();
                break;
            default:
                printf("Wrong choice\n");
        }
        printf("Do you want to perform more operations? Press 1 for Yes, else 0: ");
        scanf("%d", &c);
    } while (c != 0);
    return 0;
}
