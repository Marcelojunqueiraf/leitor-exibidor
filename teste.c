#include <stdio.h>

int change (int* pointer) {
  *pointer = 1;
}

int main () {
  int a = 0;

  change(&a);

  printf("%d\n", a);
}