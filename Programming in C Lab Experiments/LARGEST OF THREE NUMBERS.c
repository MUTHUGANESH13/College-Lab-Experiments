#include<stdio.h>
#include<conio.h>
void main() {
    int a, b, c;
    printf("Enter the three numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a > b && a > c)
        printf("The biggest number is: %d", a);
    else if (b > a && b > c)
        printf("The biggest number is: %d", b);
    else
        printf("The biggest number is: %d", c);
    getch(); 
}
