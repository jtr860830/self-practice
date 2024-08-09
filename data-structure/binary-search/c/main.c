#include <stdio.h>

#define CMP(a, b) (((a) < (b)) ? -1 : ((a) == (b)) ? 0 : 1)

int bin_search(int arr[], int len, int target) {
  int left = 0, right = len - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
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

int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int len = sizeof(arr) / sizeof(arr[0]);
  int target = 100;
  int result = bin_search(arr, len, target);
  printf("Index of %d is %d\n", target, result);
}
