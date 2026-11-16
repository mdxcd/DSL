// Depth First Search (DFS) using Stack (Iterative)

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int start, int n) {
    visited[start] = 1;
    stack[++top] = start;

    printf("DFS Traversal: ");
    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", curr);

        for (int i = n - 1; i >= 0; i--) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dfs(start, n);
    return 0;
}
