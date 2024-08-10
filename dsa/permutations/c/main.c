#include <stdio.h>

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void perm(char *list, int i, int n) {
  if (i == n) {
    for (int j = 0; j <= n; j++) {
      printf("%c", list[j]);
    }
    puts("");
  } else {
    for (int j = i; j <= n; j++) {
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
