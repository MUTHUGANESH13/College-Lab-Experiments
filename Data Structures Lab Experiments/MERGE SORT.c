#include <stdio.h>
#define MAX 20

void print(int *a, int sz) {
    int i;
    for (i = 0; i < sz; i++)
        printf("%d\t", a[i]);
}

void merge(int a[], int low, int mid, int high) {
    int temp[MAX];
    int left = low, right = mid + 1, current = 0, i;
    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp[current] = a[left];
            left++;
        } else {
            temp[current] = a[right];
            right++;
        }
        current++;
    }
    if (left > mid) {
        for (i = right; i <= high; i++) {
            temp[current] = a[i];
            current++;
        }
    } else {
        for (i = left; i <= mid; i++) {
            temp[current] = a[i];
            current++;
        }
    }
    for (i = 0; i <= high - low; i++)
        a[i + low] = temp[i];
}

void merge_sort(int a[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main() {
    int n, i;
    int a[MAX];
    printf("Enter total elements: ");
    scanf("%d", &n);
    printf("Enter %d Elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    printf("The sorted List...\n");
    print(a, n);
    return 0;
}
