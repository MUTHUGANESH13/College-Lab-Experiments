#include <stdio.h>

void dnf(int arr[], int arr_size) {
    int low = 0, high = arr_size - 1, mid = 0, temp;
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
        }
    }
}

void main() {
    int arr[] = {0, 1, 0, 1, 2, 0, 1, 2};
    int i, n = sizeof(arr) / sizeof(arr[0]);
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    dnf(arr, n);
    printf("\nArray after executing the DNFS algorithm: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    getch();
}
