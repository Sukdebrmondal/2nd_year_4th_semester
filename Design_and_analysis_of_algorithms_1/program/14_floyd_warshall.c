#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF 99999 // A large value to represent infinity

// Floyd-Warshall algorithm
void floydWarshall(int **graph, int size)
{
    int **dist = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        dist[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Main algorithm
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the matrix in formatted style (no labels)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(dist[i]);
    }
    free(dist);
}

int main()
{
    int size;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &size);

    int **graph = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        graph[i] = (int *)malloc(size * sizeof(int));

    printf("Enter the adjacency matrix (use 'i' for INF):\n");
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

    printf("\nShortest distance matrix:\n");
    floydWarshall(graph, size);

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// Enter the number of vertices in the graph: 4
// Enter the adjacency matrix (use 'i' for INF):
// 4 i 7 i
// 8 4 i 2
// i 9 2 i
// 5 2 8 i

// Shortest distance matrix:
//    4  16   7  18
//    7   4  10   2
//   16   9   2  11
//    5   2   8   4

// Enter the number of vertices in the graph: 6
// Enter the adjacency matrix (use 'i' for INF):
// 1 i 3 i 5 2
// i 5 4 i 3 6
// 3 2 6 i 8 i
// i 3 2 8 i 5
// i 4 7 4 i 9
// i 9 7 3 i 2

// Shortest distance matrix:
//    1   5   3   5   5   2
//    7   5   4   7   3   6
//    3   2   6   8   5   5
//    5   3   2   8   6   5
//    9   4   6   4   7   9
//    8   6   5   3   9   2