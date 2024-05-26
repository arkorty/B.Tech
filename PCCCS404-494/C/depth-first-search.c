/*
   Program: Depth-First Search (DFS) Algorithm
   Description: This program implements the Depth-First Search algorithm for traversing a graph starting from a given
   vertex. It uses an adjacency list representation of the graph.

   Structures:
     - node_t: Represents a node in the graph, containing data and a pointer to the next node.

   Functions:
     - create_node(int data): Creates a new graph node with the given data.
     - add_edge(node_t *graph[], int source, int dest): Adds an edge from the source vertex to the destination vertex in
   the graph.
     - dfs_util(node_t *graph[], int vertex, bool visited[]): Recursive utility function for DFS traversal.
     - dfs(node_t *graph[], int num_vertices): Performs DFS traversal on the entire graph.
     - main(): Entry point of the program. Initializes the graph, calls the dfs function, and prints the DFS traversal
   result.

   Input:
     - Number of vertices in the graph.
     - Edges of the graph represented as source-destination pairs.

   Output:
     - DFS traversal starting from the specified vertex.

   Approach:
     - The program starts by defining necessary structures and functions: node_t, create_node, add_edge, dfs_util, and
   dfs.
     - It uses an adjacency list representation to store the graph.
     - DFS traversal is performed recursively starting from each unvisited vertex.
     - When a vertex is visited, it is marked as visited, printed, and all its unvisited neighbors are recursively
   explored.
     - The main function initializes the graph, calls the dfs function, and prints the DFS traversal result.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph node
typedef struct node_t {
    int data;
    struct node_t *next;
} node_t;

// Function to create a new graph node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add an edge to the graph
void add_edge(node_t *graph[], int source, int dest) {
    node_t *new_node = create_node(dest);
    new_node->next = graph[source];
    graph[source] = new_node;
}

// Function to perform DFS traversal
void dfs_util(node_t *graph[], int vertex, bool visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all unvisited neighbors
    node_t *temp = graph[vertex];
    while (temp) {
        if (!visited[temp->data]) {
            dfs_util(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal from a given vertex
void dfs(node_t *graph[], int num_vertices) {
    bool visited[num_vertices];
    for (int i = 0; i < num_vertices; ++i) {
        visited[i] = false;
    }

    // Call the recursive helper function to start DFS traversal
    for (int i = 0; i < num_vertices; ++i) {
        if (!visited[i]) {
            dfs_util(graph, i, visited);
        }
    }
    printf("\n");
}

int main() {
    int num_vertices = 6;
    node_t *graph[num_vertices];

    // Create an adjacency list representation of graph
    for (int i = 0; i < num_vertices; ++i) {
        graph[i] = NULL;
    }

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 3, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 4, 0);
    add_edge(graph, 4, 5);

    printf("Following is Depth First Traversal (starting from vertex 0)\n");
    dfs(graph, num_vertices);

    return 0;
}
