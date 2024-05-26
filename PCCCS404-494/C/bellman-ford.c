/*
   Program: Bellman-Ford Algorithm for Shortest Paths

   Description:
       This program implements the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other
   vertices in a directed graph with possibly negative edge weights. The algorithm also detects negative weight cycles
   if present.

   Structures:
       - edge_t: Represents a weighted edge in the graph, containing source, destination, and weight.
       - graph_t: Represents a connected, directed, and weighted graph, containing the number of vertices, number of
   edges, and an array of edges.

   Functions:
       - create_graph(int V, int E): Creates a graph with a specified number of vertices and edges.
       - print(int dist[], int n): Utility function to print an array of distances.
       - bellman_ford(graph_t *graph, int src): Finds the shortest distances from the source vertex to all other
   vertices using the Bellman-Ford algorithm.
       - main(): Entry point of the program, initializes the graph, adds edges, and calls the Bellman-Ford algorithm.

   Input:
       - Number of vertices (V) and edges (E) in the graph.
       - Edges of the graph represented as source-destination pairs with corresponding weights.

   Output:
       - Shortest distances from the source vertex to all other vertices.
       - Detection of negative weight cycles if present.

   Approach:
       1. The program starts by defining structures for representing edges and the graph.
       2. Functions are defined to create a graph, print an array of distances, and implement the Bellman-Ford
   algorithm.
       3. In the main function, a graph is created, edges are added to it, and the Bellman-Ford algorithm is applied to
   find the shortest distances from a specified source vertex.
       4. The shortest distances are printed, and if a negative weight cycle is detected, it is also reported.
       5. Memory allocated for the graph is freed to prevent memory leaks.

   Driver's code:
       - The main function initializes the graph, adds edges, calls the Bellman-Ford algorithm, and prints the result.
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a weighted edge in the graph
typedef struct edge_t {
    int src;    // Source vertex
    int dest;   // Destination vertex
    int weight; // Weight of the edge
} edge_t;

// Structure to represent a connected, directed, and weighted graph
typedef struct graph_t {
    int V;               // Number of vertices
    int E;               // Number of edges
    struct edge_t *edge; // Array of edges
} graph_t;

// Function to create a graph with V vertices and E edges
struct graph_t *create_graph(int V, int E) {
    struct graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->V = V;
    graph->E = E;
    graph->edge = (edge_t *)malloc(E * sizeof(edge_t));
    return graph;
}

// Utility function to print the solution
void print(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Main function to find shortest distances from src to all other vertices
// using Bellman-Ford algorithm. The function also detects negative weight cycles.
void bellman_ford(graph_t *graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V]; // Array to store distances

    // Step 1: Initialize distances from src to all other vertices as infinity
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0; // Distance from source to itself is 0

    // Step 2: Relax all edges |V| - 1 times.
    // A shortest path from src to any other vertex can have at most |V| - 1 edges
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int src = graph->edge[j].src;
            int dest = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            // If there is a shorter path throsrcgh destertex src
            if (dist[src] != INT_MAX && dist[src] + weight < dist[dest])
                dist[dest] = dist[src] + weight; // Update distance to dest
        }
    }

    // Step 3: Check for negative-weight cycles.
    // The above step guarantees shortest distances if the graph doesn't contain negative-weight cycles.
    // If we get a shorter path, then there is a negative-weight cycle.
    for (int i = 0; i < E; i++) {
        int src = graph->edge[i].src;
        int dest = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        // If there is a shorter path through vertex u
        if (dist[src] != INT_MAX && dist[src] + weight < dist[dest]) {
            printf("Graph contains negative weight cycle"); // Negative-weight cycle detected
            return;
        }
    }

    // No negative-weight cycle found, print the distances
    print(dist, V);

    return;
}

// Driver's code
int main() {
    // Number of vertices and edges in the graph
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    graph_t *graph = create_graph(V, E);

    // Adding edges to the graph
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1; // 0-1 with weight -1
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4; // 0-2 with weight 4
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3; // 1-2 with weight 3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2; // 1-3 with weight 2
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2; // 1-4 with weight 2
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5; // 3-2 with weight 5
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1; // 3-1 with weight 1
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3; // 4-3 with weight -3

    bellman_ford(graph, 0); // Calculate shortest distances from vertex 0

    return 0;
}
