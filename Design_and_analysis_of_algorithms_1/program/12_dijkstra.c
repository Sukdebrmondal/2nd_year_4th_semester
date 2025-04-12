#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 9  
#define INF INT_MAX  

// Function to find the vertex with the minimum distance
int minDistance(int dist[], bool visited[]) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < MAX; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the shortest distances
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < MAX; i++)
        printf("%c \t %d\n", i + 'a', dist[i]);
}

// Dijkstra’s Algorithm using an adjacency matrix
void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX];  
    bool visited[MAX]; 

    // Initialize all distances to INF and visited[] to false
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0; 

    for (int count = 0; count < MAX - 1; count++) {
        int u = minDistance(dist, visited); 
        if (u == -1) break;  // All remaining nodes are unreachable
        visited[u] = true;

        for (int v = 0; v < MAX; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

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
    dijkstra(graph, source);

    return 0;
}
