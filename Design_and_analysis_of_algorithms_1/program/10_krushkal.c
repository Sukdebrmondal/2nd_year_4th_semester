#include <stdio.h>

#define MAX 9
#define INF 99999

int parent[MAX];

// Function to find the set of an element i (with path compression)
int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

// Function to perform union of two sets
void unionSets(int u, int v) {
    int setU = findSet(u);
    int setV = findSet(v);
    parent[setU] = setV;
}

// Function to implement Kruskal's Algorithm using Adjacency Matrix
void kruskalMST(int graph[MAX][MAX], int V) {
    int edgeCount = 0;
    int minCost = 0;

    // Initialize parent array (Disjoint Set)
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Convert adjacency matrix to an edge list
    int edges[MAX * MAX][3];  // Each row contains {src, dest, weight}
    int edgeIndex = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {  // Avoid duplicate edges
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                edges[edgeIndex][0] = i;
                edges[edgeIndex][1] = j;
                edges[edgeIndex][2] = graph[i][j];
                edgeIndex++;
            }
        }
    }

    // Sort edges by weight (Bubble Sort for simplicity)
    for (int i = 0; i < edgeIndex - 1; i++) {
        for (int j = 0; j < edgeIndex - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp[3];
                for (int k = 0; k < 3; k++) {
                    temp[k] = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp[k];
                }
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    while (edgeCount < V - 1 && edgeIndex > 0) {
        int u = edges[0][0];
        int v = edges[0][1];
        int weight = edges[0][2];

        // Remove the first edge from the list
        for (int i = 0; i < edgeIndex - 1; i++) {
            for (int k = 0; k < 3; k++) {
                edges[i][k] = edges[i + 1][k];
            }
        }
        edgeIndex--;

        // Check if adding this edge creates a cycle
        if (findSet(u) != findSet(v)) {
            printf("%c - %c \tWeight: %d\n", u + 'a', v + 'a', weight);
            unionSets(u, v);
            minCost += weight;
            edgeCount++;
        }
    }

    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}

// Main function
int main() {
    int V = 9;
    int graph[MAX][MAX] = {
        {0, 4, INF, INF, INF, INF, INF, 8, INF},
        {4, 0, 8, INF, INF, INF, INF, 11, INF},
        {INF, 8, 0, 7, INF, INF, 4, INF, 2},
        {INF, INF, 7, 0, 9, 14, INF, INF, INF},
        {INF, INF, INF, 9, 0, 10, INF, INF, INF},
        {INF, INF, INF, 14, 10, 0, 2, INF, INF},
        {INF, INF, 4, INF, INF, 2, 0, 1, 6},
        {8, 11, INF, INF, INF, INF, 1, 0, 7},
        {INF, INF, 2, INF, INF, INF, 6, 7, 0}
    };

    kruskalMST(graph, V);

    return 0;
}


// output
// Edges in the Minimum Spanning Tree:
// g - h   Weight: 1
// c - i   Weight: 2
// f - g   Weight: 2
// a - b   Weight: 4
// c - g   Weight: 4
// c - d   Weight: 7
// a - h   Weight: 8
// d - e   Weight: 9
// Minimum Cost of Spanning Tree: 37