#include<stdio.h>
#include<conio.h>
void main() {
    int a[3][3], b[3][3], c[3][3], i, j;
    clrscr();
    printf("\nEnter the elements of A\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    printf("\n\nEnter the Elements of Matrix B\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &b[i][j]);
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            c[i][j] = a[i][j] + b[i][j];
    printf("\n\nThe sum of the two given matrices is\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
    getch();
}
