// write a c program to implement breadth first search using adjacency matrix representation.

#include<stdio.h>
#include<stdlib.h>

// Structure for queue implementation
struct queue{
    int size;
    int rear;
    int front;
    int * arr;
};

// Function to check if the queue is empty
int isEmpty(struct queue * q){
    if(q->rear == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the queue is full
int isFull(struct queue * q){
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to display the queue elements
void show_queue(struct queue * q){
    int a = (q->front == -1)?0:q->front+1;
    int b = (q->rear == -1)?0:q->rear;
    if(isEmpty(q)){
        printf("queue: ");
    }
    else{
        printf("queue: ");
        for(int i = a; i <= b; i++){
            printf("%d ", q->arr[i]);
        }
    }
    printf("\n");
}

// Function to add an element to the queue
void enqueue(struct queue * q, int val){
    if(isFull(q)){
        printf("queue is full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("queue is empty!");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main(){
    // Initializing the queue
    struct queue q;
    q.rear = q.front = -1;
    q.size = 20;
    q.arr = (int*) malloc(q.size * sizeof(int));
    
    int node_size;
    printf("Enter the number of graph nodes: \n");
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
    printf("node is %d \n", start);
    visited[start] = 1;
    enqueue(&q, start);
    
    // BFS traversal
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int i = 0; i < node_size; i++){
            if(adj_mat[node][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(&q, i);
                printf("node is %d \n", i);
            }
        }
    }
    printf("Finally Breadth first search is completed!!");
    
    return 0;
}

/*
Enter the number of graph nodes:
5
Enter the adjacency matrix of the graph:
1 0 0 1 1
1 0 1 0 1
0 1 0 1 0
0 1 1 0 0
1 0 1 0 1
Enter the starting node:
0
node is 0
node is 3
node is 4
node is 1
node is 2
Finally Breadth first search is completed!!


Enter the number of graph nodes:
7
Enter the adjacency matrix of the graph:
0 1 1 1 0 0 0
1 0 1 0 0 0 0
1 1 0 1 1 0 0
1 0 1 0 1 0 0
0 0 1 1 0 1 1
0 0 0 0 1 0 0
1 0 1 0 1 0 0
Enter the starting node:
0
node is 0
node is 1
node is 2
node is 3
node is 4
node is 5
node is 6
Finally Breadth first search is completed!!
*/