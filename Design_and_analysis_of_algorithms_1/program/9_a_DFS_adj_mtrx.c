// write a c program of depth first search using adjacency matrix.

#include<stdio.h>
void dfs(int i,int size,int adj_mat[size][size],int visited[size]){
    visited[i] = 1;
    printf("node is %d \n",i);
    for(int j = 0;j<size;j++){
        if(adj_mat[i][j] == 1 && visited[j] == 0){
            visited[j] = 1;
            dfs(j,size,adj_mat,visited);
        }
    }

}
int main(){
    int node_size;
    printf("enter the number of graph nodes: \n");
    scanf("%d", &node_size);

    // Initializing visited array to track visited nodes
    int visited[node_size];
    for(int i = 0; i < node_size; i++){
        visited[i] = 0;
    }

    // Input adjacency matrix
    int adj_mat[node_size][node_size];
    printf("Enter the adjacency matrix of the graph:\n");
    for(int i = 0; i < node_size; i++){
        for(int j = 0; j < node_size; j++){
            scanf("%d", &adj_mat[i][j]);
        }
    }
    
    int start;
    printf("Enter the starting node: \n");
    scanf("%d", &start);

    dfs(start,node_size,adj_mat,visited);
}


// output 

// enter the number of graph nodes:
// 6
// Enter the adjacency matrix of the graph:
// 0 1 1 0 0 0
// 1 0 0 1 1 0
// 1 0 0 0 0 0
// 0 1 0 0 0 1
// 0 1 0 0 0 1
// 0 0 0 1 1 0
// Enter the starting node:
// 0
// node is 0
// node is 1
// node is 3
// node is 5
// node is 4
// node is 2