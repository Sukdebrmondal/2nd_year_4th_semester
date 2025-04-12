#include <stdio.h>

#define INF 99999  // Large value to represent infinity
#define MAX 9      // Number of vertices in the graph

// Function to print the final shortest distance matrix
void printSolution(int dist[MAX][MAX]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall algorithm
void floydWarshall(int graph[MAX][MAX]) {
    int dist[MAX][MAX];

    // Step 1: Initialize the distance matrix with graph values
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Consider each vertex as an intermediate vertex
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printSolution(dist);
}

// Driver function
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

    floydWarshall(graph);
    return 0;
}




// output 
// The following matrix shows the shortest distances between every pair of vertices:
//       0      4     12     19     21     11      9      8     14
//       4      0      8     15     24     14     12     11     10
//      12      8      0      7     16      6      4      5      2
//      19     15      7      0      9     13     11     12      9
//      21     24     16      9      0     10     12     13     18
//      11     14      6     13     10      0      2      3      8
//       9     12      4     11     12      2      0      1      6
//       8     11      5     12     13      3      1      0      7
//      14     10      2      9     18      8      6      7      0