#include<stdio.h>
#include<conio.h>
long int fact(int);
void main() {
    int n;
    clrscr();
    printf("Enter the number whose factorial is to be found: ");
    scanf("%d", &n);
    printf("The factorial of %d is: %ld\n", n, fact(n));
    getch();
}
long int fact(int n) {
    if(n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
