/*
   Program: Quick Sort Implementation
   Description: This program implements the quick sort algorithm to sort an array of integers in ascending order. Quick
   sort is a divide-and-conquer algorithm that works by selecting a pivot element from the array and partitioning the
   other elements into two subarrays according to whether they are less than or greater than the pivot. It then
   recursively sorts the subarrays.

   Functions:
     - swap(int *a, int *b): Swaps the values of two integer pointers.
     - partition(int arr[], int low, int high): Chooses a pivot element within the subarray, partitions the array around
   the pivot, and returns the index of the pivot.
     - quicksort_recursive(int arr[], int low, int high): Recursively sorts the array using the quicksort algorithm.
     - quicksort(int arr[], int n): Wrapper function for quicksort_recursive.
     - main(): Entry point of the program. Initializes an array, calls quicksort, and prints the sorted array.

   Input:
     - An unsorted array of integers.

   Output:
     - The sorted array in ascending order.

   Approach:
     - The program starts by declaring the necessary functions for quick sort: swap, partition, quicksort_recursive, and
   quicksort.
     - The swap function swaps the values of two integer pointers.
     - The partition function selects a pivot element within the subarray, partitions the array around the pivot, and
   returns the index of the pivot.
     - The quicksort_recursive function recursively sorts the array by partitioning it into subarrays and sorting them.
     - The quicksort function is a wrapper function for quicksort_recursive and ensures that the input array is not NULL
   and has at least one element.
     - In the main function, an unsorted array is initialized, and its size is calculated.
     - The unsorted array is printed, quicksort is called to sort the array, and then the sorted array is printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    // Randomly pick a pivot element within the subarray
    srand(time(NULL));
    int pivot_index = low + rand() % (high - low + 1);
    swap(&arr[pivot_index], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort_recursive(arr, low, pi - 1);
        quicksort_recursive(arr, pi + 1, high);
    }
}

void quicksort(int arr[], int n) {
    if (arr != NULL && n > 0) {
        quicksort_recursive(arr, 0, n - 1);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
