#include <stdio.h>
#include <conio.h>

void quicksort(int *, int, int);
int partition(int*, int, int);

void main() {
    int arr[10];
    int i;
    clrscr();
    printf("Enter the numbers to Quick sort:\n");
    for(i = 0; i <= 9; i++)
        scanf("%d", &arr[i]);
    printf("Quick sort.\n");
    printf("\nArray before sorting:\n");
    for(i = 0; i <= 9; i++)
        printf("%d\t", arr[i]);
    quicksort(arr, 0, 9);
    printf("\nArray after sorting:\n");
    for(i = 0; i <= 9; i++)
        printf("%d\t", arr[i]);
    getch();
}

void quicksort(int a[], int lower, int upper) {
    int pivot;
    if (upper > lower) {
        pivot = partition(a, lower, upper);
        quicksort(a, lower, pivot - 1);
        quicksort(a, pivot + 1, upper);
    }
}

int partition(int a[], int lower, int upper) {
    int p, q, t, i;
    p = lower + 1;
    q = upper;
    i = a[lower];
    while (q >= p) {
        while (a[p] < i)
            p++;
        while (a[q] > i)
            q--;
        if (q > p) {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
        }
    }
    t = a[lower];
    a[lower] = a[q];
    a[q] = t;
    return q;
}
