/*
   Program: 0-1 Knapsack Problem
   Description: This program solves the 0-1 knapsack problem using dynamic programming. Given a set of items, each with
   a weight and a value, and a knapsack with a capacity W, it finds the maximum value that can be obtained by selecting
   a subset of the items while keeping the total weight within the knapsack capacity.

   Functions:
     - knapsack(int val[], int wt[], int W, int n): Solves the knapsack problem and returns the maximum value that can
   be obtained.
     - main(): Entry point of the program. Initializes the values, weights, and knapsack capacity, calls the knapsack
   function, and prints the maximum value.

   Input:
     - Arrays of values (val[]) and weights (wt[]) of items.
     - Knapsack capacity (W).

   Output:
     - Maximum value that can be obtained by selecting a subset of items within the knapsack capacity.

   Approach:
     - The program starts by defining the knapsack function and the main function.
     - The knapsack function solves the 0-1 knapsack problem using dynamic programming.
     - It initializes a 2D array dp[][] to store the maximum value that can be obtained with items up to index i and
   knapsack capacity j.
     - Base cases are set where either the number of items or knapsack capacity is 0.
     - It builds the DP table iteratively, considering two cases for each item: including the item or excluding it.
     - In the main function, values, weights, and knapsack capacity are initialized, and the knapsack function is called
   to find the maximum value.
     - The maximum value is then printed.
*/

#include <math.h>
#include <stdio.h>

int knapsack(int val[], int wt[], int W, int n) {
    int dp[n + 1][W + 1];

    // Base Cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = fmax(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in knapsack = %d\n", knapsack(val, wt, W, n));

    return 0;
}
