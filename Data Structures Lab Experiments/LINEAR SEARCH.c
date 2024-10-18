#include<stdio.h>

void main() {
    int a[5], i;
    int ele, temp = 0;
    printf("enter the array elements\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    printf("Enter the element to be search\n");
    scanf("%d", &ele);
    for (i = 0; i < 5; i++) {
        if (a[i] == ele) {
            temp = 1;
            printf("Element found %d ,position=%d\n", ele, i + 1);
        }
    }
    if (!temp)
        printf("Element not found\n");
}
