#include <stdio.h>

void DFS(int);
void BFS(int);

int G[10][10], visited[10], q[20], n, f = 0, r = -1;

int main() {
    int i, j, ch;
    printf("GRAPH TRAVERSALS\n\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\n1. DEPTH FIRST SEARCH (DFS)\n2. BREADTH FIRST SEARCH (BFS)\n");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            printf("DEPTH FIRST SEARCH OF THE GIVEN GRAPH IS:\n");
            DFS(0);
            break;
        case 2:
            printf("BREADTH FIRST SEARCH OF THE GIVEN GRAPH IS:\n");
            BFS(0);
            for (i = 0; i < n; i++)
                if (visited[i])
                    printf("%d\t", i);
            break;
    }
    return 0;
}

void DFS(int i) {
    int j;
    printf("%d\t", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(j);
}

void BFS(int v) {
    int i;
    for (i = 0; i < n; i++)
        if (G[v][i] && !visited[i])
            q[++r] = i;
    if (f <= r) {
        visited[q[f]] = 1;
        BFS(q[f++]);
    }
}
