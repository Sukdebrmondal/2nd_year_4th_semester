#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define INF INT_MAX

// Function to print the solution
void printSolution(int dist[], int size)
{
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", i);
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

// Bellman-Ford Algorithm
void bellmanFord(int **graph, int src, int size)
{
    int dist[size];

    // Step 1: Initialize distances
    for (int i = 0; i < size; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int k = 0; k < size - 1; k++)
    {
        for (int u = 0; u < size; u++)
        {
            for (int v = 0; v < size; v++)
            {
                if (graph[u][v] != INF && dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int u = 0; u < size; u++)
    {
        for (int v = 0; v < size; v++)
        {
            if (graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                printf("Graph contains a negative weight cycle!\n");
                return;
            }
        }
    }

    printSolution(dist, size);
}

int main()
{
    int size;
    printf("Enter the number of graph nodes:\n");
    scanf("%d", &size);

    // Allocate memory for adjacency matrix
    int **graph = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        graph[i] = (int *)malloc(size * sizeof(int));

    printf("Enter the adjacency matrix (use 'i' for INF / no edge):\n");
    char input[10];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%s", input);
            if (input[0] == 'i' || input[0] == 'I')
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input);
        }
    }

    int source;
    printf("Enter the source node (0 to %d):\n", size - 1);
    scanf("%d", &source);

    if (source < 0 || source >= size)
    {
        printf("Invalid source node!\n");
        return 1;
    }

    bellmanFord(graph, source, size);

    // Free memory
    for (int i = 0; i < size; i++)
        free(graph[i]);
    free(graph);

    return 0;
}

// Enter the number of graph nodes:
// 4
// Enter the adjacency matrix (use 'i' for INF / no edge):
// 8 i 2 i
// i i 5 7
// 8 46 3 i
// 3 2 i 1
// Enter the source node (0 to 3):
// 0
// Vertex  Distance from Source
// 0       0
// 1       48
// 2       2
// 3       55

// Enter the number of graph nodes:
// 5
// Enter the adjacency matrix (use 'i' for INF / no edge):
// 9 2 i i 4
// i 2 9 i 4
// 6 3 i i 2
// i 3 5 i 6
// i 8 5 2 3
// Enter the source node (0 to 4):
// 0
// Vertex  Distance from Source
// 0       0
// 1       2
// 2       9
// 3       6
// 4       4