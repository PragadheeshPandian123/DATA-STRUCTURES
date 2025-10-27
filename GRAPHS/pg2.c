#include <stdio.h>

#define MAX 100  // Maximum number of vertices

// Function to create the graph
void createGraph(int graph[MAX][MAX], int *size) {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", size);

    // Initialize all elements to 0
    for (int i = 0; i < *size; i++)
        for (int j = 0; j < *size; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge as (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);

        if (src >= 0 && src < *size && dest >= 0 && dest < *size) {
            graph[src][dest] = 1;
            graph[dest][src] = 1;  // comment this for directed graph
        } else {
            printf("Invalid edge (%d, %d) ignored!\n", src, dest);
        }
    }

    printf("Graph created successfully!\n");
}

// Function to display the adjacency matrix and connections
void displayGraph(int graph[MAX][MAX], int size) {
    if (size == 0) {
        printf("Graph not created yet!\n");
        return;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph Connections:\n");
    for (int i = 0; i < size; i++) {
        printf("Vertex %d -> ", i);
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    }
}

// BFS Traversal
void BFS(int graph[MAX][MAX], int size, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < size; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS helper function (recursive)
void DFSUtil(int graph[MAX][MAX], int size, int vertex, int visited[MAX]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < size; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, size, i, visited);
        }
    }
}

// DFS Traversal
void DFS(int graph[MAX][MAX], int size, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal starting from vertex %d: ", start);
    DFSUtil(graph, size, start, visited);
    printf("\n");
}

int main() {
    int graph[MAX][MAX];
    int size = 0, choice, start;

    do {
        printf("\n====== Graph using Adjacency Matrix ======\n");
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. BFS Traversal\n");
        printf("4. DFS Traversal\n");
        printf("5. Clear Graph\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph(graph, &size);
                break;

            case 2:
                displayGraph(graph, size);
                break;

            case 3:
                if (size == 0) {
                    printf("Create the graph first!\n");
                    break;
                }
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < size)
                    BFS(graph, size, start);
                else
                    printf("Invalid vertex!\n");
                break;

            case 4:
                if (size == 0) {
                    printf("Create the graph first!\n");
                    break;
                }
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < size)
                    DFS(graph, size, start);
                else
                    printf("Invalid vertex!\n");
                break;

            case 5:
                size = 0;
                printf("Graph cleared successfully!\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}