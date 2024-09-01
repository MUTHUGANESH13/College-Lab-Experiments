#include<stdio.h>
#include<conio.h>
void main()
{
    int x, a;
    clrscr();
    printf("Enter the value of x: ");
    scanf("%d", &x);
    a = 3*x*x + 2*x + 1;
    printf("The value of 'a' = %d", a);
    getch();
}
