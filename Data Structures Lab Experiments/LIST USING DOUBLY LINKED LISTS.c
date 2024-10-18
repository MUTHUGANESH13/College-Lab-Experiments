#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define null 0
struct dnode {
    int data;
    struct dnode *prev;
    struct dnode *next;
} *head = null;

int num, q, i = 2;

void create() {
    struct dnode *temp, *temp1;
    head = malloc(sizeof(struct dnode));
    printf("Node: 1\n");
    scanf("%d", &num);
    head->data = num;
    head->prev = null;
    head->next = null;
    temp1 = head;
    do {
        printf("Node: %d\n", i);
        scanf("%d", &num);
        temp1->next = malloc(sizeof(struct dnode));
        temp = temp1->next;
        temp->data = num;
        temp->prev = temp1;
        temp1 = temp1->next;
        printf("Continue?\n");
        scanf("%d", &q);
        i++;
    } while (q != 0);
    temp->next = null;
}

void insert_at_first() {
    struct dnode *temp;
    temp = malloc(sizeof(struct dnode));
    printf("Enter the data to be inserted in that node\n");
    scanf("%d", &num);
    temp->data = num;
    head->prev = temp;
    temp->next = head;
    temp->prev = null;
    head = temp;
}

void insert_at_last() {
    struct dnode *temp;
    temp = head;
    printf("Enter the data to be inserted in that node\n");
    scanf("%d", &num);
    while (temp->next != null)
        temp = temp->next;
    temp->next = malloc(sizeof(struct dnode));
    temp->next->data = num;
    temp->next->prev = temp;
    temp->next->next = null;
}

void insert_at_middle() {
    struct dnode *temp, *temp1;
    temp = head;
    printf("Enter the position\n");
    scanf("%d", &q);
    printf("Enter the number to be inserted in that node\n");
    scanf("%d", &num);
    while (temp->data != q)
        temp = temp->next;
    temp1 = malloc(sizeof(struct dnode));
    temp1->data = num;
    temp1->next = temp->next;
    temp1->prev = temp;
    temp->next = temp1;
    if (temp1->next != null)
        temp1->next->prev = temp1;
}

void delete_at_first() {
    struct dnode *temp;
    temp = head;
    head = head->next;
    free(temp);
    if (head != null)
        head->prev = null;
}

void delete_at_last() {
    struct dnode *temp;
    temp = head;
    while (temp->next != null)
        temp = temp->next;
    temp->prev->next = null;
    free(temp);
}

void delete_at_middle() {
    struct dnode *temp;
    temp = head;
    printf("Enter the position\n");
    scanf("%d", &q);
    while (temp->data != q)
        temp = temp->next;
    temp->prev->next = temp->next;
    if (temp->next != null)
        temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    struct dnode *temp;
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
    } while (c != 2);
    getch();
}
