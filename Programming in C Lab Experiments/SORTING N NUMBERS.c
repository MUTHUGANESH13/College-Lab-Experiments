#include<stdio.h>
#include<conio.h>
void main() {
    int n, i, j, temp, x[50];
    clrscr();
    printf("Enter the total number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) 
        scanf("%d", &x[i]);
    for(i = 0; i < n - 1; i++) 
        for(j = i + 1; j < n; j++) 
            if(x[i] > x[j]) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
    printf("\nNumbers in ascending order:\n");
    for(i = 0; i < n; i++) 
        printf("\t%d", x[i]);
    getch();
}
