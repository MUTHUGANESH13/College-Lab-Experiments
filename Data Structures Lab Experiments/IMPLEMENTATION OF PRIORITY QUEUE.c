#include <stdio.h>
#include <stdlib.h>
#define max 20

void insert(int);
int del();
int findmin();
void disp();

int a[max], size = 0;

int main() {
    int ch, n;
    printf("1. Insert 2. DeleteMin 3. FindMin 4. Display 5. Exit\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                n = del();
                printf("Deleted element is %d\n", n);
                break;
            case 3:
                n = findmin();
                printf("Minimum element is %d\n", n);
                break;
            case 4:
                disp();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (1);
    return 0;
}

void insert(int n) {
    int i;
    if (size == max) {
        printf("Queue is full\n");
        return;
    }
    size++;
    a[size] = n;
    for (i = size; i > 1 && a[i / 2] > a[i]; i /= 2) {
        a[i] = a[i / 2];
    }
    a[i] = n;
}

int del() {
    if (size == 0) {
        printf("Queue is empty\n");
        exit(0);
    }
    int min = a[1];
    int last = a[size--];
    int i, c;
    for (i = 1; i * 2 <= size; i = c) {
        c = i * 2;
        if (c + 1 <= size && a[c + 1] < a[c]) {
            c++;
        }
        if (last > a[c]) {
            a[i] = a[c];
        } else {
            break;
        }
    }
    a[i] = last;
    return min;
}

void disp() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue:\n");
    for (int i = 1; i <= size; i++) {
        printf("%d\n", a[i]);
    }
}

int findmin() {
    if (size != 0)
        return a[1];
    else {
        printf("Priority queue is empty\n");
        exit(0);
    }
}
