/*
   Program: Prim's Algorithm for Minimum Spanning Tree

   Description:
       This program implements Prim's algorithm to find the minimum spanning tree (MST) of a weighted undirected graph.
   Prim's algorithm works by starting with an arbitrary vertex and gradually expanding the MST by selecting the smallest
   edge that connects a vertex in the MST to a vertex outside the MST. The algorithm continues until all vertices are
   included in the MST.

   Structures:
       - edge_t: Represents an edge in the graph, containing a vertex and its weight.
       - graph_t: Represents the graph, containing the number of vertices and an adjacency matrix.

   Functions:
       - create_graph(int num_vertices): Creates a new graph with the specified number of vertices.
       - add_edge(graph_t *graph, int src, int dest, int weight): Adds an edge with a given weight between two vertices
   in the graph.
       - prim_mst(graph_t *graph): Finds the minimum spanning tree of the graph using Prim's algorithm.
       - free_graph(graph_t *graph): Frees the memory allocated for the graph.

   Input:
       - The number of vertices in the graph.
       - Edges of the graph with their corresponding weights.

   Output:
       - The minimum spanning tree represented as a set of edges with their weights.

   Approach:
       1. The program starts by defining structures for graph nodes and the graph itself.
       2. Functions are defined to create a new graph, add edges to the graph, find the minimum spanning tree using
   Prim's algorithm, and free memory allocated for the graph.
       3. In the main function, a graph is created, edges are added to it, and Prim's algorithm is applied to find the
   minimum spanning tree.
       4. The minimum spanning tree is printed as a set of edges with their weights.
       5. Finally, memory allocated for the graph is freed to prevent memory leaks.

   Driver code:
       - The main function initializes the graph, adds edges, finds the minimum spanning tree, prints the result, and
   frees the memory.
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a graph node
typedef struct {
    int vertex;
    int weight;
} edge_t;

// Define a struct to represent a graph
typedef struct {
    int num_vertices;
    int **adj_matrix;
} graph_t;

// Function to create a new graph
graph_t *create_graph(int num_vertices) {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;

    // Allocate memory for adjacency matrix
    graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void add_edge(graph_t *graph, int src, int dest, int weight) {
    graph->adj_matrix[src][dest] = weight;
    graph->adj_matrix[dest][src] = weight;
}

// Function to find the minimum spanning tree using Prim's algorithm
void prim_mst(graph_t *graph) {
    int *parent = (int *)malloc(graph->num_vertices * sizeof(int));
    int *key = (int *)malloc(graph->num_vertices * sizeof(int));
    int *mst_set = (int *)malloc(graph->num_vertices * sizeof(int));

    // Initialize key values and parent array
    for (int i = 0; i < graph->num_vertices; i++) {
        key[i] = INT_MAX;
        mst_set[i] = 0;
    }

    // Start with first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->num_vertices - 1; count++) {
        int min_key = INT_MAX, min_index;

        // Find the vertex with minimum key value
        for (int v = 0; v < graph->num_vertices; v++) {
            if (mst_set[v] == 0 && key[v] < min_key) {
                min_key = key[v];
                min_index = v;
            }
        }

        mst_set[min_index] = 1;

        // Update key values and parent indices of adjacent vertices
        for (int v = 0; v < graph->num_vertices; v++) {
            if (graph->adj_matrix[min_index][v] && mst_set[v] == 0 && graph->adj_matrix[min_index][v] < key[v]) {
                parent[v] = min_index;
                key[v] = graph->adj_matrix[min_index][v];
            }
        }
    }

    // Print the minimum spanning tree
    printf("Edge\tWeight\n");
    for (int i = 1; i < graph->num_vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph->adj_matrix[i][parent[i]]);
    }

    // Free allocated memory
    free(parent);
    free(key);
    free(mst_set);
}

// Function to free memory allocated for the graph
void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

int main() {
    int num_vertices = 5;
    graph_t *graph = create_graph(num_vertices);

    // Adding edges to the graph
    add_edge(graph, 0, 1, 2);
    add_edge(graph, 0, 3, 6);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 1, 3, 8);
    add_edge(graph, 1, 4, 5);
    add_edge(graph, 2, 4, 7);
    add_edge(graph, 3, 4, 9);

    // Find minimum spanning tree using Prim's algorithm
    prim_mst(graph);

    // Free allocated memory
    free_graph(graph);

    return 0;
}
