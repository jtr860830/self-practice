#include <stdio.h>

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void perm(char *list, size_t i, size_t n) {
  if (i == n) {
    for (size_t j = 0; j <= n; j++) {
      printf("%c", list[j]);
    }
    puts("");
  } else {
    for (size_t j = i; j <= n; j++) {
      swap(&list[i], &list[j]);
      perm(list, i + 1, n);
      swap(&list[i], &list[j]);
    }
  }
}

int main(void) {
  char list[] = {'A', 'B', 'C', 'D'};
  perm(list, 0, 3);
}
