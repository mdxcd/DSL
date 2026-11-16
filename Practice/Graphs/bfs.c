// Breadth First Search (BFS) using Adjacency Matrix

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void bfs(int start, int n) {
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
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

    bfs(start, n);
    return 0;
}
