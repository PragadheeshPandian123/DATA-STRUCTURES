#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create graph
void createGraph(struct Node* adjList[], int* size) {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", size);

    // Initialize adjacency list
    for (int i = 0; i < *size; i++) {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge as (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);

        if (src >= 0 && src < *size && dest >= 0 && dest < *size) {
            // Add edge src -> dest
            struct Node* newNode = createNode(dest);
            newNode->next = adjList[src];
            adjList[src] = newNode;

            // Add edge dest -> src (for undirected graph)
            newNode = createNode(src);
            newNode->next = adjList[dest];
            adjList[dest] = newNode;
        } else {
            printf("Invalid edge (%d, %d) ignored!\n", src, dest);
        }
    }

    printf("Graph created successfully!\n");
}

// Function to display adjacency list
void displayGraph(struct Node* adjList[], int size) {
    if (size == 0) {
        printf("Graph not created yet!\n");
        return;
    }

    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < size; i++) {
        struct Node* temp = adjList[i];
        printf("Vertex %d -> ", i);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to clear the graph
void clearGraph(struct Node* adjList[], int* size) {
    for (int i = 0; i < *size; i++) {
        struct Node* temp = adjList[i];
        while (temp) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }
        adjList[i] = NULL;
    }
    *size = 0;
    printf("Graph cleared successfully!\n");
}

int main() {
    struct Node* adjList[MAX];
    int size = 0;
    int choice;

    do {
        printf("\n====== Graph using Adjacency List ======\n");
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. Clear Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph(adjList, &size);
                break;

            case 2:
                displayGraph(adjList, size);
                break;

            case 3:
                clearGraph(adjList, &size);
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
  