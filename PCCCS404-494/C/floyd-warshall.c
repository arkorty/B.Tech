/*
   Program: Floyd-Warshall Algorithm for All-Pairs Shortest Paths

   Description:
       This program implements the Floyd-Warshall algorithm to find the shortest distances between every pair of
   vertices in a weighted directed graph. It utilizes dynamic programming to iteratively update the shortest distances
   until the optimal solution is achieved. The algorithm handles both positive and negative edge weights but cannot
   handle graphs with negative cycles.

   Structures:
       - None

   Functions:
       - initialize_distance_matrix(int graph[V][V], int dist[V][V]): Initializes the distance matrix with the same
   values as the input graph.
       - floyd_warshall(int dist[V][V]): Performs the Floyd-Warshall algorithm to compute the shortest distances between
   every pair of vertices.
       - print_shortest_distances(int dist[V][V]): Prints the shortest distance matrix, indicating the shortest
   distances between each pair of vertices.

   Input:
       - The input is a weighted directed graph represented as an adjacency matrix 'graph[V][V]', where 'V' is the
   number of vertices.
       - Each element 'graph[i][j]' represents the weight of the edge from vertex 'i' to vertex 'j'. A value of
   'INT_MAX' indicates no direct edge between the vertices.

   Output:
       - The output is the shortest distance matrix, showing the shortest distances between every pair of vertices in
   the graph.
       - If there is no direct path between two vertices, 'INF' (infinity) is printed.
       - The matrix is printed in a tabular format for easy interpretation.

   Approach:
       1. Initialize the distance matrix with the same values as the input graph.
       2. Iterate through all intermediate vertices and update the shortest distance if a shorter path is found using
   dynamic programming.
       3. Perform relaxation on each edge (i, j) by considering all vertices as intermediate vertices.
       4. Repeat the process until the shortest distances between all pairs of vertices are computed.
       5. Print the resulting shortest distance matrix.

   Driver code:
       - The main function initializes the input graph, calls the Floyd-Warshall algorithm function, and prints the
   shortest distance matrix.
       - The input graph is provided as an adjacency matrix.
 */
#include <limits.h>
#include <stdio.h>

// Define the maximum number of vertices in the graph
#define V 4

// Function to perform the Floyd-Warshall algorithm
void floyd_warshall(int dist[V][V]) {
    // Iterate through all intermediate vertices and update the shortest distance if a shorter path is found
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update the distance
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// Function to print the shortest distance matrix
void print_shortest_distances(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// Driver code to test the implementation
int main() {
    int graph[V][V] = {
        {0, 5, INT_MAX, 10}, {INT_MAX, 0, 3, INT_MAX}, {INT_MAX, INT_MAX, 0, 1}, {INT_MAX, INT_MAX, INT_MAX, 0}};
    int dist[V][V]; // Output matrix that stores the shortest distances between every pair of vertices

    // Call the function to perform the Floyd-Warshall algorithm
    floyd_warshall(graph);

    // Print the shortest distance matrix
    print_shortest_distances(graph);

    return 0;
}
