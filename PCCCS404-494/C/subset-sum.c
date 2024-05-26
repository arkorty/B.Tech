/*
  Program: Subset Sum Checker

  Structures: None

  Functions:
    - bool subset_sum(int arr[], int n, int sum, int curr_idx, int curr_sum)
        Description: Recursive function to check if a subset with given sum exists
        Parameters:
          - arr[]: Array of integers
          - n: Size of the array
          - sum: Target sum to check for
          - curr_idx: Current index of the array being processed
          - curr_sum: Current sum of elements in the subset
        Returns:
          - true if a subset with the specified sum exists, false otherwise

  Input: None

  Output:
    - Prints whether a subset with the specified sum exists or not

  Approach:
    - Define a recursive function to check all possible subsets by including or excluding each element
    - Call the recursive function with initial parameters to determine if a subset with the specified sum exists
    - Print the result
*/

#include <stdbool.h>
#include <stdio.h>

// Function to check if a subset with given sum exists
bool subset_sum(int arr[], int n, int sum, int curr_idx, int curr_sum) {
    // If the current sum matches the target sum, return true
    if (curr_sum == sum) {
        return true;
    }

    // If we reach the end of the array or the current sum exceeds the target sum, return false
    if (n == 0 || curr_sum > sum) {
        return false;
    }

    // Try including the current element and recursively call subset_sum
    // with reduced size of the array and updated current sum
    return subset_sum(arr, n - 1, sum, curr_idx + 1, curr_sum + arr[curr_idx]) ||
           // Try excluding the current element and recursively call subset_sum
           // with reduced size of the array and same current sum
           subset_sum(arr, n - 1, sum, curr_idx + 1, curr_sum);
}

int main() {
    // Input array and target sum
    int arr[] = {3, 2, 4, 7};
    int sum = 8;
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Check if a subset with the given sum exists
    if (subset_sum(arr, n, sum, 0, 0)) {
        printf("Yes, a subset with sum %d exists\n", sum);
    } else {
        printf("No, a subset with sum %d doesn't exist\n", sum);
    }

    return 0;
}
