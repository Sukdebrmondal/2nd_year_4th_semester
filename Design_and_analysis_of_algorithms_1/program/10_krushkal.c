#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999

int *parent;

// Function to find the set of an element i (with path compression)
int findSet(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

// Function to perform union of two sets
void unionSets(int u, int v)
{
    int setU = findSet(u);
    int setV = findSet(v);
    parent[setU] = setV;
}

// Kruskal's Algorithm
void kruskalMST(int **graph, int V)
{
    parent = (int *)malloc(V * sizeof(int));
    int edgeCount = 0, minCost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Convert to edge list
    int maxEdges = V * V;
    int edges[maxEdges][3]; // {u, v, weight}
    int edgeIndex = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0 && graph[i][j] != INF)
            {
                edges[edgeIndex][0] = i;
                edges[edgeIndex][1] = j;
                edges[edgeIndex][2] = graph[i][j];
                edgeIndex++;
            }
        }
    }

    // Sort edges by weight (Bubble sort)
    for (int i = 0; i < edgeIndex - 1; i++)
    {
        for (int j = 0; j < edgeIndex - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                for (int k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < edgeIndex && edgeCount < V - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (findSet(u) != findSet(v))
        {
            printf("%c - %c \tWeight: %d\n", u + 'a', v + 'a', weight);
            unionSets(u, v);
            minCost += weight;
            edgeCount++;
        }
    }

    printf("minimum cost of spanning tree: %d\n", minCost);
    free(parent);
}

// Main function
int main()
{
    int V;
    printf("enter the number of graph nodes: ");
    scanf("%d", &V);

    // Allocate 2D adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("enter the adjacency matrix (use 'i' for INF / no edge):\n");
    char input[10];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%s", input);
            if (input[0] == 'i' || input[0] == 'I')
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input); // Convert string to integer
        }
    }

    kruskalMST(graph, V);

    // Free memory
    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// enter the number of graph nodes: 5
// enter the adjacency matrix (use 'i' for INF / no edge):
// 2 i 3 i 1
// 4 i 3 i i
// i 3 2 i 1
// 4 i i 7 1
// i 5 i 3 i
// Edges in the Minimum Spanning Tree:
// a - e   Weight: 1
// c - e   Weight: 1
// d - e   Weight: 1
// b - c   Weight: 3
// minimum cost of spanning tree: 6

// enter the number of graph nodes: 6
// enter the adjacency matrix (use 'i' for INF / no edge):
//  4 3 i i 2 9
// 4 i 6 i 5 i
// 2 i i 4 i 3
// i i 3 i 6 i
// 6 i 1 i 4 i
// 5 i 6 2 i i
// Edges in the Minimum Spanning Tree:
// a - e   Weight: 2
// a - b   Weight: 3
// c - f   Weight: 3
// c - d   Weight: 4
// b - c   Weight: 6
// minimum cost of spanning tree: 18