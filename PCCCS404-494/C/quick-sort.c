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

int lomuto_partition(int arr[], int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Randomly choose pivot
        int random_pivot = low + rand() % (high - low + 1);
        swap(&arr[random_pivot], &arr[high]);

        int pivot_index = lomuto_partition(arr, low, high);

        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    print_array(arr, n);

    srand(time(NULL)); // Seed the random number generator
    quicksort(arr, 0, n - 1);

    printf("Sorted array:   ");
    print_array(arr, n);

    return 0;
}
