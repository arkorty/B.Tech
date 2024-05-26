
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
      return mid;
    else if (arr[mid] > key)
      return high = mid - 1;
    else
      return low = mid + 1;
  }

  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;
  int result = binarySearch(arr, 0, n - 1, x);
  if (result == -1)
    printf("Element is not present in array\n");
  else
    printf("Element is present at index %d\n", result);
  return 0;
}
