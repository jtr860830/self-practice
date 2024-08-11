#include <stdio.h>

#define CMP(a, b) (((a) < (b)) ? -1 : ((a) == (b)) ? 0 : 1)

int bin_search(int arr[], size_t left, size_t right, int target) {
  while (left <= right) {
    size_t mid = (left + right) / 2;
    switch (CMP(target, arr[mid])) {
    case -1:
      right = mid - 1;
      break;
    case 0:
      return mid;
    case 1:
      left = mid + 1;
    }
  }
  return -1;
}

int bin_search_rec(int arr[], size_t left, size_t right, int target) {
  if (left <= right) {
    size_t mid = (left + right) / 2;
    switch (CMP(target, arr[mid])) {
    case -1:
      return bin_search_rec(arr, left, mid - 1, target);
    case 0:
      return mid;
    case 1:
      return bin_search_rec(arr, mid + 1, right, target);
    }
  }
  return -1;
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t len = sizeof(arr) / sizeof(arr[0]);
  int target = 100;
  int result = bin_search_rec(arr, 0, len - 1, target);
  printf("Index of %d is %d\n", target, result);
}
