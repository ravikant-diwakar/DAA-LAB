#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int n, int startVertex) {
    int parent[MAX_VERTICES]; // Array to store the constructed MST
    int key[MAX_VERTICES];    // Key values to pick the minimum weight edge
    int mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the starting vertex in MST
    key[startVertex] = 0;
    parent[startVertex] = -1;

    // The MST will have V vertices
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Display the cost adjacency matrix of the minimum spanning tree
    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == parent[j])
                printf("%d ", graph[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    // Calculate and display the total weight of the spanning tree
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            totalWeight += graph[i][parent[i]];
        }
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, startVertex;

    // Read input from the "inUnAdjMat.dat" file
    FILE *inputFile = fopen("inUnAdjMat.dat", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the number of vertices and the starting vertex
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    if (n <= 0 || startVertex < 1 || startVertex > n) {
        printf("Invalid input. Please provide valid values.\n");
        return 1;
    }

    // Read the cost adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(inputFile, "%d", &graph[i][j]) != 1) {
                printf("Error reading input file.\n");
                fclose(inputFile);
                return 1;
            }
        }
    }

    fclose(inputFile);

    // Call the Prim's algorithm function to find the minimum spanning tree
    primMST(graph, n, startVertex - 1);

    return 0;
}
