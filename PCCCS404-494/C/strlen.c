#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *)calloc(sizeof(char), 32);
    strcpy(str, "this is a test");

    printf("\"%s\" is of length: %lu\n", str, strlen(str));

    return 0;
}