#include <stdio.h>

int main() {
  int a = 0;
  for (int i = 0; i < 12345; i++) {
    a += 6789;
  }
  printf("%d\n", a);
  return 0;
}