#include <stdio.h>

void strCopy(char *src, char *dest) {
  while (*src) {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
}

int main() {
  char source[] = "Hello, World!";
  char destination[20];

  strCopy(source, destination);
  printf("Copied string: %s\n", destination);

  return 0;
}
