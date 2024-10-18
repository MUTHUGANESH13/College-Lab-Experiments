#include<stdio.h>
#include<conio.h>

void main() {
    int i, first = 0, last, middle, n, search, a[100];
    clrscr();
    printf("\nIMPLEMENTATION OF BINARY SEARCH\n");
    printf("----------------------------------------------------\n");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements in ascending order\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);
    last = n - 1;
    middle = (first + last) / 2;
    while (first <= last) {
        if (a[middle] < search)
            first = middle + 1;
        else if (a[middle] == search) {
            printf("\n%d found at location %d\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
        printf("\nNot found! %d is not present in the list.\n", search);
    getch();
}
