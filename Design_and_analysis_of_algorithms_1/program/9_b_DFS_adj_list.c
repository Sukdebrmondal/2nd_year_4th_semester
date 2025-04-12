#include<stdio.h>
#include<stdlib.h>


// Structure to represent a graph node
struct node {
    int node;
    struct node *add;
};

// Function to find index of a node in the adjacency list
int find_index(int value, int node_size, struct node adj_list[]) {
    for (int i = 0; i < node_size; i++) {
        if (adj_list[i].node == value) {
            return i;
        }
    }
    return -1;
}

// Depth First Search (DFS) function
void dfs(int node_value, int node_size, struct node adj_list[], int visited[]) {
    int index = find_index(node_value, node_size, adj_list);
    if (index == -1 || visited[index] == 1) {
        return;
    }

    visited[index] = 1;
    printf("Visited node: %d\n", node_value);

    struct node *link = adj_list[index].add;
    while (link != NULL) {
        dfs(link->node, node_size, adj_list, visited);
        link = link->add;
    }
}

int main() {
    int node_size;
    printf("Enter the number of graph nodes: \n");
    scanf("%d", &node_size);

    int visited[node_size];
    for(int i = 0; i < node_size; i++) {
        visited[i] = 0;
    }

    struct node adj_list[node_size];

    // Creating adjacency list
    for(int i = 0; i < node_size; i++) {
        printf("Enter the node number: \n");
        scanf("%d", &adj_list[i].node);
        adj_list[i].add = NULL;  // Initialize adjacency list head

        int n;
        printf("Number of edges connected to node %d: \n", adj_list[i].node);
        scanf("%d", &n);

        struct node *link = NULL;
        for(int j = 0; j < n; j++) {
            struct node *a = (struct node *)malloc(sizeof(struct node));
            printf("Enter connected node: \n");
            scanf("%d", &a->node);
            a->add = NULL;
            
            if (j == 0) {
                adj_list[i].add = a;
                link = a;
            } else {
                link->add = a;
                link = a;
            }
        }
    }

    // Printing adjacency list
    printf("\nGraph adjacency list:\n");
    for(int i = 0; i < node_size; i++) {
        struct node *link = adj_list[i].add;
        printf("%d -> ", adj_list[i].node);
        while (link != NULL) {
            printf("%d ", link->node);
            link = link->add;
        }
        printf("\n");
    }

    // Running DFS
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("Starting DFS from node %d\n", start);
    dfs(start, node_size, adj_list, visited);

    // Freeing allocated memory
    for (int i = 0; i < node_size; i++) {
        struct node *link = adj_list[i].add;
        while (link != NULL) {
            struct node *temp = link;
            link = link->add;
            free(temp);
        }
    }

    return 0;
}
