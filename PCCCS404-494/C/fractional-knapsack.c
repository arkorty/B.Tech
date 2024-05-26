/*
   Program: Fractional Knapsack Problem
   Description: This program solves the fractional knapsack problem using a greedy approach. Given a set of items, each
   with a value and a weight, and a knapsack with a capacity, it finds the maximum value that can be obtained by
   selecting fractional amounts of items while keeping the total weight within the knapsack capacity.

   Structures:
     - item: Represents an item with a value and a weight.

   Functions:
     - fractional_knapsack(item_t items[], int n, float capacity): Solves the fractional knapsack problem and returns
   the maximum value that can be obtained.
     - main(): Entry point of the program. Initializes the items, calls the fractional_knapsack function, and prints the
   maximum value.

   Input:
     - Array of items with values and weights.
     - Number of items (n).
     - Knapsack capacity (capacity).

   Output:
     - Maximum value that can be obtained by selecting fractional amounts of items within the knapsack capacity.

   Approach:
     - The program starts by defining the fractional_knapsack function and the main function.
     - The fractional_knapsack function sorts the items by their value-to-weight ratio in descending order.
     - It then iterates through the sorted items, adding items to the knapsack until the capacity is exhausted.
     - If an item can be fully added to the knapsack, its entire value is added.
     - If an item cannot be fully added, a fraction of the item is added based on the remaining capacity.
     - The main function initializes the items, calls the fractional_knapsack function, and prints the maximum value
   obtained.
*/

#include <stdio.h>

typedef struct item {
    float value;
    float weight;
} item_t;

float fractional_knapsack(item_t items[], int n, float capacity) {
    // Sort items by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].value / items[i].weight < items[j].value / items[j].weight) {
                item_t temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float total_value = 0.0f;
    float remaining_capacity = capacity;

    // Iterate through sorted items
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining_capacity) {
            // Add entire item
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        } else {
            // Add a fraction of the item
            float fraction = remaining_capacity / items[i].weight;
            total_value += items[i].value * fraction;
            break; // No more capacity left, exit loop
        }
    }

    return total_value;
}

int main() {
    item_t items[] = {{60.0f, 10.0f}, {100.0f, 20.0f}, {120.0f, 30.0f}};
    int n = sizeof(items) / sizeof(items[0]);
    float capacity = 50.0f;

    float max_value = fractional_knapsack(items, n, capacity);
    printf("Maximum value in fractional knapsack = %f\n", max_value);

    return 0;
}
