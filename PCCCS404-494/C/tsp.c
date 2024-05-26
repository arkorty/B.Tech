
#include <limits.h>
#include <math.h>
#include <stdio.h>

#define N 4 // Number of cities

// Function to solve the Traveling Salesman Problem using dynamic programming
int tsp(int graph[N][N]) {
    int dp[1 << N]
          [N]; // dp[mask][current] stores the minimum cost to visit all cities in the mask ending at the current city

    // Initialize dp array with maximum possible value
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int current = 0; current < N; current++) {
            dp[mask][current] = INT_MAX;
        }
    }

    // Initialize starting point (mask = 1, starting city = 0)
    dp[1][0] = 0;

    // Iterate over all possible subsets of cities
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int current = 0; current < N; current++) {
            // If current city is not in the mask, continue
            if (!(mask & (1 << current)))
                continue;

            // Iterate over all possible previous cities
            for (int prev = 0; prev < N; prev++) {
                // If previous city is not in the mask, continue
                if (!(mask & (1 << prev)))
                    continue;

                // Update dp[mask][current] using the cost to reach prev and then to current
                dp[mask][current] = fmin(dp[mask][current], dp[mask ^ (1 << current)][prev] + graph[prev][current]);
            }
        }
    }

    // The answer is the minimum cost to reach any city from the last city in the mask
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        ans = fmin(ans, dp[(1 << N) - 1][i] + graph[i][0]); // Calculate the cost of returning back to the starting city
    }

    return ans;
}

int main() {
    int graph[N][N] = {{0, 10, 15, 20}, // Cost matrix representing distances between cities
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};

    // Call the tsp function and store the minimum cost
    int min_cost = tsp(graph);

    // Print the minimum cost to visit all cities
    printf("Minimum cost to visit all cities: %d\n", min_cost);

    return 0;
}
