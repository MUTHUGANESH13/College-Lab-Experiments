#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define null 0
struct node {
    int data;
    struct node *next;
} *head = null;

int num, q, i = 2;

void create() {
    struct node *temp, *temp1;
    head = malloc(sizeof(struct node));
    printf("Node: 1\n");
    scanf("%d", &num);
    head->data = num;
    head->next = null;
    temp = head;
    do {
        printf("Node: %d\n", i);
        scanf("%d", &num);
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->data = num;
        printf("Continue? \n");
        scanf("%d", &q);
        i++;
    } while (q != 0);
    temp->next = null;
}

void insert_at_first() {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("Enter the data to be inserted in that node\n");
    scanf("%d", &num);
    temp->data = num;
    temp->next = head;
    head = temp;
}

void insert_at_last() {
    struct node *temp, *t;
    temp = head;
    printf("Enter the data to be inserted in that node\n");
    scanf("%d", &num);
    while (temp->next != null)
        temp = temp->next;
    t = malloc(sizeof(struct node));
    t->data = num;
    t->next = null;
    temp->next = t;
}

void insert_at_middle() {
    struct node *a, *temp;
    a = head;
    printf("Enter the position\n");
    scanf("%d", &q);
    printf("Enter the number to be inserted in that node\n");
    scanf("%d", &num);
    while (a->data != q)
        a = a->next;
    temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = a->next;
    a->next = temp;
}

void delete_at_first() {
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
}

void delete_at_last() {
    struct node *temp, *a;
    temp = head;
    while (temp->next != null) {
        a = temp;
        temp = temp->next;
    }
    a->next = null;
    free(temp);
}

void delete_at_middle() {
    struct node *temp, *a;
    temp = head;
    printf("Enter the position\n");
    scanf("%d", &q);
    while (temp->data != q) {
        a = temp;
        temp = temp->next;
    }
    a->next = temp->next;
    free(temp);
}

void display() {
    struct node *temp;
    temp = head;
    printf("head->");
    while (temp != null) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("null");
}

void main() {
    int ch, c;
    clrscr();
    create();
    do {
        printf("What operation do you want to do?\n");
        printf("1. Insert at first\n2. Insert at last\n3. Insert at middle\n4. Delete at first\n5. Delete at last\n6. Delete at middle\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_last();
                break;
            case 3:
                insert_at_middle();
                break;
            case 4:
                delete_at_first();
                break;
            case 5:
                delete_at_last();
                break;
            case 6:
                delete_at_middle();
                break;
            default:
                printf("Wrong choice\n");
        }
        printf("The modified list is\n");
        display();
        printf("\nDo you want to continue?\n1. Yes\n2. No\n");
        scanf("%d", &c);
    } while (c != 0);
    getch();
}
