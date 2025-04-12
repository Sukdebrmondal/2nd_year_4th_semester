#include <stdio.h>
#include <limits.h>

#define MAX 9  // Number of vertices
#define INF INT_MAX  // Infinite value

// Function to print the solution
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < MAX; i++) {
        printf("%c \t %d\n", i + 'a', dist[i]);
    }
}

// Bellman-Ford Algorithm
void bellmanFord(int graph[MAX][MAX], int src) {
    int dist[MAX]; 

    // Step 1: Initialize distances
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int k = 0; k < MAX - 1; k++) {
        for (int u = 0; u < MAX; u++) {
            for (int v = 0; v < MAX; v++) {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int u = 0; u < MAX; u++) {
        for (int v = 0; v < MAX; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains a negative weight cycle!\n");
                return;
            }
        }
    }

    // Print final shortest distances
    printSolution(dist);
}

int main() {
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

    int source = 0;  
    bellmanFord(graph, source);

    return 0;
}




// output
// Vertex   Distance from Source
// a        0
// b        4
// c        12
// d        19
// e        21
// f        11
// g        9
// h        8
// i        14