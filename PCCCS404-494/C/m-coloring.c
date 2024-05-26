/*
   Program: Graph Coloring
   Description: This program implements the graph coloring algorithm to assign colors to the vertices of a graph such
   that no two adjacent vertices have the same color. It checks whether it's possible to color the graph with a given
   number of colors and prints the assigned colors for each vertex if a solution exists.

   Functions:
     - is_safe(int v, bool graph[V][V], int color[], int c): Checks if assigning color c to vertex v is safe, i.e., it
   does not conflict with the adjacent vertices.
     - color_graph(bool graph[V][V], int m, int color[], int v): Recursively tries to color the graph vertices. Returns
   true if the graph can be colored with m colors, false otherwise.
     - graph_coloring(bool graph[V][V], int m): Initializes the color array and calls color_graph to determine if a
   solution exists. Prints the assigned colors if a solution is found.
     - main(): Entry point of the program. Initializes the graph adjacency matrix and the number of colors and calls
   graph_coloring.

   Input:
     - An adjacency matrix representing the graph.
     - The number of colors available for coloring the graph.

   Output:
     - Whether a solution exists to color the graph with the given number of colors.
     - If a solution exists, the colors assigned to each vertex.

   Approach:
     - The program starts by defining the necessary functions: is_safe, color_graph, and graph_coloring.
     - The is_safe function checks if assigning a particular color to a vertex is safe, i.e., it does not conflict with
   adjacent vertices.
     - The color_graph function recursively tries to color the graph vertices. It backtracks if a coloring is not
   possible with the current color.
     - The graph_coloring function initializes the color array and calls color_graph to determine if a solution exists.
   If a solution is found, it prints the assigned colors for each vertex.
     - In the main function, an adjacency matrix representing the graph is initialized, and the number of colors
   available is specified. The graph_coloring function is then called to determine if a solution exists and to print the
   assigned colors.
*/

#include <stdbool.h>
#include <stdio.h>

#define V 4

bool is_safe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool color_graph(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c)) {
            color[v] = c;

            if (color_graph(graph, m, color, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graph_coloring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!color_graph(graph, m, color, 0)) {
        printf("Solution does not exist");
        return false;
    }

    char colors[][6] = {"Red", "Blue", "Green"};

    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> %s\n", i, colors[color[i] - 1]);
    return true;
}

int main() {
    bool graph[V][V] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    int m = 3;
    graph_coloring(graph, m);
    return 0;
}
