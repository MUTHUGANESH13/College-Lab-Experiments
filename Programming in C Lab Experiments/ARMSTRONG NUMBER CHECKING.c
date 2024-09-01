#include <stdio.h>
#include <conio.h>
void main() {
    long int a, arm, b, e;
    clrscr();
    printf("Enter a Number: ");
    scanf("%ld", &a);    
    arm = 0;
    e = a;    
    while (a > 0) {
        b = a % 10;
        arm += b * b * b;
        a = a / 10;
    }    
    if (e == arm)
        printf("The Given Number is an Armstrong Number");
    else
        printf("The Given Number is not an Armstrong Number");    
    getch();
}
