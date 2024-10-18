#include <stdio.h>
#include <stdlib.h>

typedef struct node *position;
typedef struct node *tree;

struct node {
    int element;
    tree left;
    tree right;
};

tree insert(int x, tree t);
position findmin(tree t);
position findmax(tree t);
tree deletion(int x, tree t);
void inorder(tree t);

int main() {
    tree t = NULL, s;
    int ch, num;
    char c = 'y';

    do {
        printf("\n1. Insertion");
        printf("\n2. Find Minimum");
        printf("\n3. Find Maximum");
        printf("\n4. Deletion");
        printf("\n5. Display Inorder");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &num);
                t = insert(num, t);
                break;
            case 2:
                s = findmin(t);
                if (s != NULL)
                    printf("\nThe minimum data is %d", s->element);
                else
                    printf("\nThe tree is empty.");
                break;
            case 3:
                s = findmax(t);
                if (s != NULL)
                    printf("\nThe maximum data is %d", s->element);
                else
                    printf("\nThe tree is empty.");
                break;
            case 4:
                printf("\nEnter the data to be deleted: ");
                scanf("%d", &num);
                t = deletion(num, t);
                break;
            case 5:
                printf("Tree (Inorder): ");
                inorder(t);
                printf("\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &c); // Added space to consume newline
    } while(c == 'y');

    return 0;
}

tree insert(int x, tree t) {
    if (t == NULL) {
        t = (struct node*)malloc(sizeof(struct node));
        t->element = x;
        t->left = t->right = NULL;
    } else {
        if (x < t->element)
            t->left = insert(x, t->left);
        else
            t->right = insert(x, t->right);
    }
    return t;
}

position findmin(tree t) {
    if (t != NULL) {
        while (t->left != NULL)
            t = t->left;
    }
    return t;
}

position findmax(tree t) {
    if (t != NULL) {
        while (t->right != NULL)
            t = t->right;
    }
    return t;
}

tree deletion(int x, tree t) {
    position tmpcell;
    if (t == NULL)
        return NULL; // Return NULL if the tree is empty

    if (x < t->element)
        t->left = deletion(x, t->left);
    else if (x > t->element)
        t->right = deletion(x, t->right);
    else if (t->left != NULL && t->right != NULL) {
        tmpcell = findmin(t->right);
        t->element = tmpcell->element;
        t->right = deletion(t->element, t->right);
    } else {
        tmpcell = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        free(tmpcell);
    }
    return t;
}

void inorder(tree t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d\t", t->element);
        inorder(t->right);
    }
}
