/*
   Program: Breadth-First Search (BFS) Algorithm
   Description: This program implements the Breadth-First Search algorithm for traversing a graph starting from a given
   vertex. It uses an adjacency matrix to represent the graph and a queue to perform BFS traversal.

   Constants:
     - max_vertices: Maximum number of vertices in the graph.

   Structures:
     - queue_t: Represents a queue for BFS traversal, containing front, rear, size, capacity, and an array to store
   items.

   Functions:
     - enqueue(struct queue_t *queue, int item): Enqueues an item into the queue.
     - dequeue(struct queue_t *queue): Dequeues an item from the queue.
     - is_full(struct queue_t *queue): Checks if the queue is full.
     - is_empty(struct queue_t *queue): Checks if the queue is empty.
     - bfs(int adj_matrix[][max_vertices], int v, int start_vertex): Performs BFS traversal starting from the given
   start_vertex.
     - main(): Entry point of the program. Gets the number of vertices, adjacency matrix, and starting vertex from the
   user, calls the bfs function, and prints the BFS traversal result.

   Input:
     - Number of vertices in the graph.
     - Adjacency matrix representing the graph (0 for no edge, 1 for edge).
     - Starting vertex for BFS traversal.

   Output:
     - BFS traversal starting from the specified vertex.

   Approach:
     - The program starts by defining necessary functions: enqueue, dequeue, is_full, is_empty, and bfs.
     - It uses an adjacency matrix to represent the graph.
     - BFS traversal is performed starting from the given start_vertex using a queue.
     - Vertices are marked as visited and enqueued into the queue one by one.
     - For each vertex dequeued from the queue, its adjacent vertices are explored and enqueued if they are not visited.
     - The main function gets input from the user, calls the bfs function, and prints the BFS traversal result.
*/

#include <stdio.h>
#include <stdlib.h>

#define max_vertices 100

typedef struct queue_t {
    int front;
    int rear;
    int size;
    unsigned capacity;
    int items[max_vertices];
} queue_t;

void enqueue(struct queue_t *queue, int item);

int dequeue(struct queue_t *queue);

int is_full(struct queue_t *queue);

int is_empty(struct queue_t *queue);

// function to perform BFS traversal from a given vertex
void bfs(int adj_matrix[][max_vertices], int v, int start_vertex) {
    // array to store visited status of vertices
    int visited[v];

    // create a queue for BFS (structure definition within the function)

    // allocate memory for the queue
    struct queue_t *queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    queue->capacity = v;
    queue->size = 0;
    queue->front = queue->rear = -1;

    // initialize all vertices as not visited
    for (int i = 0; i < v; ++i) {
        visited[i] = 0;
    }

    // mark the current node as visited and enqueue it
    visited[start_vertex] = 1;
    enqueue(queue, start_vertex);

    while (!is_empty(queue)) {
        // dequeue a vertex from queue and print it
        int current = dequeue(queue);
        printf("%d ", current);

        // get all adjacent vertices of the dequeued vertex
        for (int i = 0; i < v; ++i) {
            // if adjacent vertex has an edge and hasn't been visited, add it to the queue
            if (adj_matrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    // free the allocated memory for the queue
    free(queue);
}

// function to create a queue element (definition within bfs)
void enqueue(struct queue_t *queue, int item) {
    if (is_full(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size = queue->size + 1;
}

// function to check if the queue is full (definition within bfs)
int is_full(struct queue_t *queue) { return (queue->size == queue->capacity); }

// function to check if the queue is empty (definition within bfs)
int is_empty(struct queue_t *queue) { return (queue->size == 0); }

// function to remove an item from queue (definition within bfs)
int dequeue(struct queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int main() {
    int v; // number of vertices in the graph

    // get the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    // create an adjacency matrix to represent the graph
    int adj_matrix[max_vertices][max_vertices];

    // get the adjacency matrix from the user (assuming 0 for no edge, 1 for edge)
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    // get the starting vertex for BFS traversal
    int start_vertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);

    // perform BFS traversal
    printf("BFS traversal starting from vertex %d: \n", start_vertex);
    bfs(adj_matrix, v, start_vertex);

    return 0;
}
