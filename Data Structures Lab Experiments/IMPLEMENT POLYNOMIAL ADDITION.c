#include <stdio.h>
#include <malloc.h>
#define null 0

struct polynode {
    int coeff;
    int exp;
    struct polynode *next;
} *poly1, *poly2, *poly3;

void createpoly1();
void createpoly2();
void polyadd();
void disp();

int main() {
    printf("\n To create poly1........");
    createpoly1();
    printf("\n To create poly2.........");
    createpoly2();
    printf("\n Adding polynomials...");
    polyadd();
    return 0;
}

void createpoly1() {
    struct polynode *temp, *a;
    int i, n, c, e;
    printf("\nEnter the number of terms for the 1st polynomial: ");
    scanf("%d", &n);
    
    if (n > 0) {
        printf("\nEnter the coefficient for term 1: ");
        scanf("%d", &c);
        printf("\nEnter the exponent for term 1: ");
        scanf("%d", &e);
        
        poly1 = malloc(sizeof(struct polynode));
        poly1->coeff = c;
        poly1->exp = e;
        poly1->next = null;
        temp = poly1;
        
        for (i = 1; i < n; i++) {
            printf("\nEnter the coefficient for next term: ");
            scanf("%d", &c);
            printf("\nEnter the exponent for next term: ");
            scanf("%d", &e);
            
            temp->next = malloc(sizeof(struct polynode));
            temp = temp->next;
            temp->coeff = c;
            temp->exp = e;
            temp->next = null;
        }
        
        a = poly1;
        printf("\n1st Polynomial: ");
        while (a != null) {
            printf("%d(x^%d)", a->coeff, a->exp);
            if (a->next != null) printf(" + ");
            a = a->next;
        }
    } else {
        printf("\nInvalid number of terms.");
    }
}

void createpoly2() {
    struct polynode *temp, *a;
    int i, n, c, e;
    printf("\nEnter the number of terms for the 2nd polynomial: ");
    scanf("%d", &n);
    
    if (n > 0) {
        printf("\nEnter the coefficient for term 1: ");
        scanf("%d", &c);
        printf("\nEnter the exponent for term 1: ");
        scanf("%d", &e);
        
        poly2 = malloc(sizeof(struct polynode));
        poly2->coeff = c;
        poly2->exp = e;
        poly2->next = null;
        temp = poly2;
        
        for (i = 1; i < n; i++) {
            printf("\nEnter the coefficient for next term: ");
            scanf("%d", &c);
            printf("\nEnter the exponent for next term: ");
            scanf("%d", &e);
            
            temp->next = malloc(sizeof(struct polynode));
            temp = temp->next;
            temp->coeff = c;
            temp->exp = e;
            temp->next = null;
        }
        
        a = poly2;
        printf("\n2nd Polynomial: ");
        while (a != null) {
            printf("%d(x^%d)", a->coeff, a->exp);
            if (a->next != null) printf(" + ");
            a = a->next;
        }
    } else {
        printf("\nInvalid number of terms.");
    }
}

void polyadd() {
    struct polynode *x = poly1, *y = poly2, *z;
    poly3 = null;
    
    if (x == null && y == null) {
        printf("\nBoth polynomials are empty.");
        return;
    }
    
    while (x != null && y != null) {
        if (poly3 == null) {
            poly3 = malloc(sizeof(struct polynode));
            z = poly3;
        } else {
            z->next = malloc(sizeof(struct polynode));
            z = z->next;
        }
        
        if (x->exp < y->exp) {
            z->coeff = y->coeff;
            z->exp = y->exp;
            y = y->next;
        } else if (x->exp > y->exp) {
            z->coeff = x->coeff;
            z->exp = x->exp;
            x = x->next;
        } else {
            z->coeff = x->coeff + y->coeff;
            z->exp = x->exp;
            x = x->next;
            y = y->next;
        }
    }
    
    while (x != null) {
        z->next = malloc(sizeof(struct polynode));
        z = z->next;
        z->coeff = x->coeff;
        z->exp = x->exp;
        x = x->next;
    }
    
    while (y != null) {
        z->next = malloc(sizeof(struct polynode));
        z = z->next;
        z->coeff = y->coeff;
        z->exp = y->exp;
        y = y->next;
    }
    
    z->next = null;
    disp();
}

void disp() {
    struct polynode *a = poly3;
    printf("\nResultant Polynomial: ");
    while (a != null) {
        printf("%d(x^%d)", a->coeff, a->exp);
        if (a->next != null) printf(" + ");
        a = a->next;
    }
}
