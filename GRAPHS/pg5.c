#include <stdio.h>

#define MAX 10

int parent[MAX];

// Function to find the parent (with path compression)
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]); // Path compression
    return parent[i];
}

// Function to join two sets
void unionSet(int u, int v) {
    int parentU = find(u);
    int parentV = find(v);
    parent[parentU] = parentV;
}

int main() {
    int n, adj[MAX][MAX];
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // Initialize parent array (each vertex is its own parent)
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    int edgeCount = 0;

    // Kruskal’s Algorithm
    while (edgeCount < n - 1) {
        int min = 9999, a = -1, b = -1;

        // Find the smallest edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] != 0 && adj[i][j] < min) {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a == -1 || b == -1) break; // No edge found

        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            unionSet(a, b);
            edgeCount++;
        }

        // Mark edge as used
        adj[a][b] = adj[b][a] = 0;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
