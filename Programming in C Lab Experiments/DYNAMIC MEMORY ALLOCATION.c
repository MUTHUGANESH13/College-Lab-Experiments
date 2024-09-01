#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr;
    int n = 5, i;
    printf("Enter number of elements: %d\n", n);
    ptr = (int*)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        printf("Memory successfully allocated using calloc.\n");
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
        printf("The elements of the array are:\n");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        printf("\n\n");
        n = 10;
        printf("Enter the new size of the array: %d\n", n);
        ptr = realloc(ptr, n * sizeof(int));
        if (ptr == NULL) {
            printf("Memory not re-allocated.\n");
            exit(0);
        } else {
            printf("Memory successfully re-allocated using realloc.\n");
            for (i = 5; i < n; ++i) {
                ptr[i] = i + 1;
            }
            printf("The elements of the array are:\n");
            for (i = 0; i < n; ++i) {
                printf("%d, ", ptr[i]);
            }
            printf("\n");
        }
    }
    free(ptr);
    return 0;
}
