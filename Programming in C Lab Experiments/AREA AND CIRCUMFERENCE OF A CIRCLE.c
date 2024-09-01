#include<stdio.h>
#include<conio.h>
void main()
{
    float radius, area, circumference;
    clrscr();
    printf("\nEnter the Radius to find the Area and Circumference of the Circle\n");
    scanf("%f", &radius);
    area = 3.14 * radius * radius;
    circumference = 2 * 3.14 * radius;
    printf("\nThe Area of the Circle is %f\nThe Circumference of the Circle is %f", area, circumference);
    getch();
}
