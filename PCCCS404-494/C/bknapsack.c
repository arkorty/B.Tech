#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
  // Create a DP table to store maximum value at each weight capacity
  int K[n + 1][W + 1];

  // Build table K[][] in top-down manner
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      // If no items or no weight capacity, no value
      if (i == 0 || w == 0) {
        K[i][w] = 0;
      } else {
        // If current item weight is less than capacity, consider including it
        if (wt[i - 1] <= w) {
          K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
        } else {
          // If item weight is more than capacity, exclude it
          K[i][w] = K[i - 1][w];
        }
      }
    }
  }

  // Return the maximum value achievable for the given weight capacity
  return K[n][W];
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);

  printf("Maximum value in knapsack = %d\n", knapsack(W, wt, val, n));

  return 0;
}
