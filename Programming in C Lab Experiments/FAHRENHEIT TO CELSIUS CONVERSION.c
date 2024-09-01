#include<stdio.h>
#include<conio.h>
void main()
{
    float fahrenheit, celsius, x;
    clrscr();
    printf("Enter the degrees in Fahrenheit:\n");
    scanf("%f", &fahrenheit);
    x = fahrenheit - 32;
    celsius = x / 1.8;
    printf("\nThe Celsius Value is %6.2f C", celsius);
    getch();
}
