#include <stdio.h>
#include <conio.h>
#define max 4
#define INFINITE 1000

int allknown(int *known) {
    int i;
    for (i = 0; i < max; i++)
        if (known[i] == 0)
            return 0;
    return 1;
}

void shortpath(int cost[][max], int *pv, int *dv) {
    int known[max] = {0};
    int current = 0, i, k, dc, smalldist, dw;
    for (i = 0; i < max; i++)
        dv[i] = INFINITE;
    known[current] = 1;
    dv[0] = 0;
    current = 0;
    while (allknown(known) != 1) {
        smalldist = INFINITE;
        dc = dv[current];
        for (i = 0; i < max; i++) {
            if (known[i] == 0) {
                dw = dc + cost[current][i];
                if (dw < dv[i]) {
                    dv[i] = dw;
                    pv[i] = current;
                }
                if (dv[i] < smalldist) {
                    smalldist = dv[i];
                    k = i;
                }
            }
        }
        current = k;
        known[current] = 1;
    }
}

void main() {
    int cost[max][max] = {{INFINITE, 2, 4, INFINITE}, {2, INFINITE, 1, 5}, {4, 1, INFINITE, 2}, {INFINITE, 5, 2, INFINITE}};
    int pv[max] = {0}, i, dv[max];
    clrscr();
    shortpath(cost, pv, dv);
    printf("Vertex\t dv \tpv\n");
    for (i = 0; i < max; i++) {
        printf(" %d \t %d \t%d\n", i, dv[i], pv[i]);
    }
    getch();
}
