
#include <stdio.h>

int binarySearch2D(int arr[][4], int n, int m, int x) {
  int low = 0, high = n * m - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int i = mid / m;
    int j = mid % m;
    if (arr[i][j] == x)
      return mid;
    else if (arr[i][j] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int arr[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  int x = 16;
  int result = binarySearch2D(arr, 3, 4, x);
  if (result == -1)
    printf("Element not found\n");
  else
    printf("Element found at index %d\n", result);
  return 0;
}
