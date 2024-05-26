#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with minimum distance value, from the set of
// vertices not yet included in shortest path tree
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    // Iterate through all vertices
    for (int v = 0; v < V; v++)
        // If vertex v is not yet included in the shortest path tree and its
        // distance is less than min, update min and min_index
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    // Return the index of the vertex with minimum distance value
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int graph[V][V], int prnt[]) {
    printf("Vertex \t Distance from Source\n");
    for (int v = 1; v < V; v++)
        printf("%d - %d = %d\n", prnt[v], v, graph[v][prnt[v]]);
}

// Function that implements Dijkstra's single source shortest path algorithm for
// a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V]) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance
                 // from src to i
    int prnt[V]; // Stores the parent edge

    bool visited[V]; // visited[i] will be true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    // Distance of source vertex from itself is always 0
    dist[0] = 0;
    prnt[0] = -1;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet
        // processed. u is always equal to src in first iteration.
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            // Update dist[v] only if it is not in visited, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!visited[v] && dist[v] < graph[u][v]) {
                dist[v] = graph[u][v];
                prnt[v] = u;
            }
    }

    // Print the constructed distance array
    printSolution(graph, prnt);
}

int main() {
    int graph[V][V] = {{INT_MAX, 2, INT_MAX, 6, INT_MAX},
                       {2, INT_MAX, 3, 8, 5},
                       {INT_MAX, 3, INT_MAX, INT_MAX, 7},
                       {6, 8, INT_MAX, INT_MAX, 9},
                       {INT_MAX, 5, 7, 9, INT_MAX}};

    // Call Dijkstra's algorithm function with the given graph and source vertex
    dijkstra(graph);
    return 0;
}
