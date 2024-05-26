/*
   Program: Dijkstra's Shortest Path Algorithm
   Description: This program implements Dijkstra's algorithm to find the shortest paths from a single source vertex to
   all other vertices in a weighted graph. It uses an adjacency matrix representation of the graph.

   Structures:
     - None

   Functions:
     - init_single_source(int source, int min_dist[], int parent[]): Initializes the arrays for storing minimum
   distances and parent vertices for a single source vertex.
     - get_min_dist(int min_dist[], bool not_visited[]): Finds the vertex with the minimum distance value among the
   vertices that are not yet visited.
     - relax(int u, int v, int weight, int min_dist[], int parent[]): Relaxes an edge by updating the minimum distance
   and parent vertex if a shorter path is found.
     - is_empty(bool *not_visited): Checks if there are any vertices left to visit.
     - dijkstra(int graph[V][V], int source): Performs Dijkstra's algorithm to find the shortest paths from the source
   vertex to all other vertices in the graph.

   Input:
     - Weighted adjacency matrix representing the graph.
     - Source vertex for which shortest paths are to be found.

   Output:
     - Shortest distances from the source vertex to all other vertices.
     - Parent vertices in the shortest path tree.

   Approach:
     - The program initializes arrays for storing minimum distances and parent vertices for a single source vertex.
     - It iteratively selects the vertex with the minimum distance among those that are not yet visited and relaxes all
   its neighbors.
     - The minimum distances and parent vertices are updated accordingly.
     - Finally, it prints the shortest distances and parent vertices for all vertices in the graph.
*/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

// function to initialize the single source
void init_single_source(int source, int min_dist[], int parent[]) {
    for (int i = 0; i < V; ++i) {
        min_dist[i] = INT_MAX;
        parent[i] = -1;
    }
    min_dist[source] = 0;
}

// function to find the vertex with the minimum distance value
int get_min_dist(int min_dist[], bool not_visited[]) {
    int min_index = -1, min_weight = INT_MAX;
    for (int i = 0; i < V; ++i) {
        if (not_visited[i] && min_dist[i] < min_weight) {
            min_weight = min_dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// function to relax an edge
void relax(int u, int v, int weight, int min_dist[], int parent[]) {
    if (min_dist[u] + weight < min_dist[v]) {
        min_dist[v] = min_dist[u] + weight;
        parent[v] = u;
    }
}

// function to check if not_visited is empty
bool is_empty(bool *not_visited) {
    for (int i = 0; i < V; ++i) {
        if (not_visited[i]) {
            return true;
        };
    }

    return false;
}

// dijkstra's algorithm
void dijkstra(int graph[V][V], int source) {
    int min_dist[V];     // shortest distances from source
    int parent[V];       // parent array to store the shortest path tree
    bool not_visited[V]; // boolean array to represent set of vertices that are not visited

    // initialize arrays for a single source
    init_single_source(source, min_dist, parent);

    for (int i = 0; i < V; ++i) {
        not_visited[i] = true; // set all vertices in not_visited initially to true
    }

    while (is_empty(not_visited)) {
        int u = get_min_dist(min_dist, not_visited);

        if (u == -1) {
            break; // all vertices are processed
        }

        not_visited[u] = false; // remove u from not_visited

        // relax all neighbors of u
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != 0) { // check if there is an edge
                relax(u, v, graph[u][v], min_dist, parent);
            }
        }
    }

    // print the results
    printf("Vertex\tDist\tParent\n");
    for (int i = 0; i < V; ++i) {
        printf("%d\t%d\t%d\n", i, min_dist[i], parent[i]);
    }
}

int main() {
    int graph[V][V] = {{0, 10, 0, 5, 0}, {0, 0, 1, 2, 0}, {0, 0, 0, 0, 4}, {0, 3, 9, 0, 2}, {0, 0, 6, 0, 0}};

    int source = 0; // source vertex

    dijkstra(graph, source);

    return 0;
}
