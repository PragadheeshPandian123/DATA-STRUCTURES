#include <stdio.h>

#define MAX 100

void topologicalSort(int graph[MAX][MAX], int n) {
    int indegree[MAX] = {0}, queue[MAX];
    int front = 0, rear = 0, count = 0;

    // Step 1: Compute indegree of each vertex
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            if (graph[row][col] == 1)
                indegree[col]++;
        }
    }

    // Step 2: Enqueue all vertices with indegree = 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological Sort Order: ");

    // Step 3: Process the queue
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        count++;

        // For all adjacent vertices of current vertex
        for (int j = 0; j < n; j++) {
            if (graph[vertex][j] == 1) {
                indegree[j]--; // Remove edge
                if (indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    // Step 4: Check if a cycle exists
    if (count != n)
        printf("\nCycle detected! Topological sort not possible.\n");
    else
        printf("\n");
}

int main() {
    int n, edges, src, dest;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each directed edge (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1; // directed edge
    }

    topologicalSort(graph, n);
    return 0;
}