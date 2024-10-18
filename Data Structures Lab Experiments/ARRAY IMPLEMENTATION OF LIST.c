#include<stdio.h>
#include<conio.h>
void main() {
    int ch, a[10], x, pos, n, i, flag=0, k;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    do {
        printf("\n\n1. Creation\n2. Insert First\n3. Insert Middle");
        printf("\n4. Insert Last\n5. Delete First\n6. Delete Middle");
        printf("\n7. Delete Last\n8. Search\n9. Traverse");
        printf("\n\nEnter your choice:\t");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the elements\n");
                for(i=0; i<n; i++) {
                    scanf("%d", &a[i]);
                }
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &x);
                for(i=n-1; i>=0; i--) {
                    a[i+1] = a[i];
                }
                a[0] = x;
                n = n + 1;
                break;
            case 3:
                printf("Enter the element: ");
                scanf("%d", &x);
                printf("Enter the position value: ");
                scanf("%d", &pos);
                for(i=n-1; i>=pos; i--) {
                    a[i+1] = a[i];
                }
                a[pos] = x;
                n = n + 1;
                break;
            case 4:
                printf("Enter the element: ");
                scanf("%d", &x);
                a[n] = x;
                n = n + 1;
                break;
            case 5:
                for(i=0; i<n-1; i++) {
                    a[i] = a[i+1];
                }
                n--;
                break;
            case 6:
                printf("Enter the position value: ");
                scanf("%d", &pos);
                for(i=pos; i<n-1; i++) {
                    a[i] = a[i+1];
                }
                n--;
                break;
            case 7:
                n = n - 1;
                break;
            case 8:
                printf("Enter the element to be searched: ");
                scanf("%d", &x);
                flag = 0;
                for(i=0; i<n; i++) {
                    if(a[i] == x) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) {
                    printf("Element is found\n");
                } else {
                    printf("Element is not found\n");
                }
                break;
            case 9:
                for(i=0; i<n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
        }
        printf("\nDo you want to continue? Press 1 for yes, 0 for no: ");
        scanf("%d", &k);
    } while(k != 0);
    getch();
}
