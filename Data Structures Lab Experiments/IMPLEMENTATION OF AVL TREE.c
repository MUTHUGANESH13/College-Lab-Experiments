#include <stdio.h>
#include <stdlib.h>

typedef struct node *pos;
struct node {
    int data, h;
    pos left, right;
} *t = NULL;

int height(pos p) {
    return (p == NULL) ? -1 : p->h;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

pos SRWL(pos k2) {
    pos k1 = k2->left;
    printf("\nSingle rotation with left %d\n", k2->data);
    k2->left = k1->right;
    k1->right = k2;
    k2->h = 1 + max(height(k2->left), height(k2->right));
    k1->h = 1 + max(height(k1->left), k2->h);
    return k1;
}

pos SRWR(pos k1) {
    pos k2 = k1->right;
    printf("\nSingle rotation with right %d\n", k1->data);
    k1->right = k2->left;
    k2->left = k1;
    k1->h = 1 + max(height(k1->left), height(k1->right));
    k2->h = 1 + max(k1->h, height(k2->right));
    return k2;
}

pos DRWL(pos k3) {
    printf("\nLeft right double rotation of %d\n", k3->data);
    k3->left = SRWR(k3->left);
    return SRWL(k3);
}

pos DRWR(pos k1) {
    printf("\nRight left double rotation of %d\n", k1->data);
    k1->right = SRWL(k1->right);
    return SRWR(k1);
}

pos insert(int x, pos t) {
    if (t == NULL) {
        t = (pos)malloc(sizeof(struct node));
        t->data = x;
        t->h = 0;
        t->left = t->right = NULL;
    } else if (x < t->data) {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (x < t->left->data)
                t = SRWL(t);
            else
                t = DRWL(t);
        }
    } else if (x > t->data) {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (x > t->right->data)
                t = SRWR(t);
            else
                t = DRWR(t);
        }
    } else {
        printf("Element is already in the tree\n");
    }
    t->h = 1 + max(height(t->left), height(t->right));
    return t;
}

pos deleteavl(int x, pos t) {
    struct node *d;
    if (t == NULL) {
        printf("\nElement not found\n");
    } else if (x < t->data) {
        t->left = deleteavl(x, t->left);
    } else if (x > t->data) {
        t->right = deleteavl(x, t->right);
    } else if ((t->left == NULL) && (t->right == NULL)) {
        d = t;
        t = NULL;
        free(d);
        printf("\nElement deleted!\n");
    } else if (t->left == NULL) {
        d = t;
        t = t->right;
        free(d);
        printf("\nElement deleted!\n");
    } else if (t->right == NULL) {
        d = t;
        t = t->left;
        free(d);
        printf("\nElement deleted!\n");
    } else {
        d = findmin(t->right);
        t->data = d->data;
        t->right = deleteavl(d->data, t->right);
    }
    if (t != NULL) {
        t->h = 1 + max(height(t->left), height(t->right));
    }
    return t;
}

pos findmin(pos t) {
    if (t == NULL) return NULL;
    return (t->left == NULL) ? t : findmin(t->left);
}

pos findmax(pos t) {
    if (t != NULL) {
        while (t->right != NULL)
            t = t->right;
    }
    return t;
}

void display(pos t) {
    if (t != NULL) {
        display(t->left);
        printf("\nData: %d, Height: %d\n", t->data, t->h);
        display(t->right);
    }
}

int main() {
    int ch, n;
    pos x, y;
    do {
        printf("\n\n1. Insert 2. Display 3. Delete 4. FindMin");
        printf("\n5. FindMax 6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &n);
                t = insert(n, t);
                break;
            case 2:
                printf("Elements in the tree with their heights:");
                display(t);
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d", &n);
                t = deleteavl(n, t);
                break;
            case 4:
                x = findmin(t);
                if (x != NULL)
                    printf("The minimum element is %d\n", x->data);
                else
                    printf("The tree is empty.\n");
                break;
            case 5:
                y = findmax(t);
                if (y != NULL)
                    printf("The maximum element is %d\n", y->data);
                else
                    printf("The tree is empty.\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Enter a correct choice\n");
        }
    } while (ch != 0);
    return 0;
}
