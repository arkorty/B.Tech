/*
   Program: Merge Sort Implementation
   Description: This program implements the merge sort algorithm to sort an array of integers in ascending order. Merge
   sort is a divide-and-conquer algorithm that works by recursively dividing the array into smaller subarrays until each
   subarray consists of only one element. Then, it merges these subarrays back together in a sorted manner. The merge
   function combines two sorted subarrays into a single sorted array.

   Functions:
     - merge(int arr[], int low, int mid, int high): Merges two sorted subarrays arr[low..mid] and arr[mid+1..high].
     - merge_sort_recursive(int arr[], int low, int high): Recursively divides the array into smaller subarrays and
   sorts them.
     - merge_sort(int arr[], int n): Wrapper function for merge_sort_recursive.
     - main(): Entry point of the program. Initializes an array, calls merge_sort, and prints the sorted array.

   Input:
     - An unsorted array of integers.

   Output:
     - The sorted array in ascending order.

   Approach:
     - The program starts by declaring the necessary functions for merge sort: merge, merge_sort_recursive, and
   merge_sort.
     - The merge function merges two sorted subarrays into a single sorted array.
     - The merge_sort_recursive function recursively divides the array into smaller subarrays until each subarray has
   only one element. Then, it merges these subarrays back together.
     - The merge_sort function is a wrapper function for merge_sort_recursive and ensures that the input array is not
   NULL and has at least one element.
     - In the main function, an unsorted array is initialized, and its size is calculated.
     - The unsorted array is printed, merge_sort is called to sort the array, and then the sorted array is printed.
*/

#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[low..high]

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[]
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[]
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort_recursive(arr, low, mid);
        merge_sort_recursive(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge_sort(int arr[], int n) {
    if (arr != NULL && n > 0) {
        merge_sort_recursive(arr, 0, n - 1);
    }
}

int main() {
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
