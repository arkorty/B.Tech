
#include <stdio.h>

struct Item {
  int value, weight;
};

float fractionalKnapsack(int W, struct Item arr[], int n) {
  float totalValue = 0.0;
  int currentWeight = 0;

  for (int i = 0; i < n; i++) {
    if (currentWeight + arr[i].weight <= W) {
      currentWeight += arr[i].weight;
      totalValue += arr[i].value;
    } else {
      int remainingWeight = W - currentWeight;
      totalValue += arr[i].value * ((float)remainingWeight / arr[i].weight);
      break;
    }
  }

  return totalValue;
}

int main() {
  int W = 50; // Knapsack capacity
  struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Maximum value we can obtain = %.2f\n", fractionalKnapsack(W, arr, n));
  return 0;
}
