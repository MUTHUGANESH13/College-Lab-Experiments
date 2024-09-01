#include<stdio.h>
#include<conio.h>
void interchange(int *a, int *b);
void main() {
    int i = 5, j = 10;
    clrscr();
    printf("i and j values before interchanging: %d %d\n", i, j);
    interchange(&i, &j);
    printf("i and j values after interchange in main(): %d %d\n", i, j);
    getch();
}
void interchange(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
    printf("i and j values after interchanging inside the function: %d %d\n", *a, *b);
}
