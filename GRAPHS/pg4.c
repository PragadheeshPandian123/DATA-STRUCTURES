#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, edges;
    int adj[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges as (u v weight):\n");
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected graph
    }

    int selected[MAX] = {0};
    selected[0] = 1; // start from vertex 0
    int totalWeight = 0;

    printf("\nEdges in MST (Prim's Algorithm):\n");

    for(int count = 0; count < n - 1; count++) {
        int min = INT_MAX;
        int x = -1, y = -1;

        for(int i = 0; i < n; i++) {
            if(selected[i]) {
                for(int j = 0; j < n; j++) {
                    if(!selected[j] && adj[i][j]) {  
                        if(adj[i][j] < min) {
                            min = adj[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
 
        printf("%d - %d : %d\n", x, y, adj[x][y]);
        totalWeight += adj[x][y];
        selected[y] = 1;
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}
