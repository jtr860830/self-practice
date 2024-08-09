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
