#include <stdio.h>

#define MAX 100  // Maximum number of vertices

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
            graph[dest][src] = 1;  // comment this line for directed graph
        } else {
            printf("Invalid edge (%d, %d) ignored!\n", src, dest);
        }
    }

    printf("Graph created successfully!\n");
}

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

int main() {
    int graph[MAX][MAX];
    int size = 0;
    int choice;

    do {
        printf("\n====== Graph using Adjacency Matrix ======\n");
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. Clear Graph\n");
        printf("4. Exit\n");
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
                size = 0;
                printf("Graph cleared successfully!\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}