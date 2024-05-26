/*
   Program: Kruskal's Minimum Spanning Tree Algorithm
   Description: This program implements Kruskal's algorithm to find the minimum spanning tree (MST) of a graph. Given a
   graph represented by its edges and weights, the algorithm finds the subset of edges that connects all vertices with
   the minimum total weight without forming any cycles.

   Structures:
     - Edge: Represents an edge in the graph, containing source, destination, and weight.
     - Subset: Represents a subset for the union-find data structure, containing parent and rank.

   Functions:
     - find(struct Subset subsets[], int i): Finds the subset of an element 'i' (path compression).
     - Union(struct Subset subsets[], int x, int y): Performs the union of two sets 'x' and 'y' (Union by Rank).
     - compare(const void *a, const void *b): Compares two edges based on their weights for sorting.
     - KruskalMST(struct Edge edges[], int V, int E): Constructs the minimum spanning tree using Kruskal's algorithm.
     - main(): Entry point of the program. Initializes the graph edges, calls KruskalMST, and prints the minimum
   spanning tree and its cost.

   Input:
     - Number of vertices (V) and edges (E) in the graph.
     - An array of edges with source, destination, and weight.

   Output:
     - Edges in the constructed minimum spanning tree.
     - Minimum cost of the spanning tree.

   Approach:
     - The program starts by defining necessary structures and functions: Edge, Subset, find, Union, compare, and
   KruskalMST.
     - Kruskal's algorithm is implemented to find the minimum spanning tree:
       1. Sort all edges in non-decreasing order of their weight.
       2. Initialize V subsets with single elements.
       3. Pick the smallest edge. If including this edge does not form a cycle, include it in the result.
       4. Repeat step 3 until V-1 edges are included in the MST.
     - In the main function, the graph's edges are initialized, and KruskalMST is called to construct the MST. The
   result (minimum spanning tree) and its cost are printed.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compare(const void *a, const void *b);
void KruskalMST(struct Edge edges[], int V, int E);

int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph

    // An array of edges
    struct Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    // Find the minimum spanning tree using Kruskal's algorithm
    KruskalMST(edges, V, E);

    return 0;
}

// A utility function to find the subset of an element 'i'
int find(struct Subset subsets[], int i) {
    // Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of 'x' and 'y'
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        // If ranks are the same, then make one as root and increment its rank
        // by one
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges based on their weights
int compare(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}

// Function to construct the minimum spanning tree using Kruskal's algorithm
void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // Array to store the resultant MST
    int e = 0;             // Index variable for result[]
    int i = 0;             // Index variable for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E) {
        // Step 2: Pick the smallest edge. And increment the index for next
        // iteration
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it in the
        // result and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the constructed MST
    printf("Edges in the constructed MST:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);

    // Free dynamically allocated memory
    free(subsets);
}
