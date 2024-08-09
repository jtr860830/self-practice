#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    int min = i, temp;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    SWAP(arr[min], arr[i], temp);
  }
}

int main(void) {
  int arr[MAX_SIZE] = {0}, n;
  printf("Enter the number of numbers to generate: ");
  scanf("%d", &n);

  if (n < 1 || n > MAX_SIZE) {
    fprintf(stderr, "Invalid number\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 1000;
    printf("%d ", arr[i]);
  }

  sort(arr, n);

  puts("\nSorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return EXIT_SUCCESS;
}
