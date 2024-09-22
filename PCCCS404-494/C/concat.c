#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1 = (char *)malloc(50 * sizeof(char));
    char *str2 = (char *)malloc(50 * sizeof(char));

    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(str1, "Hello, ");
    strcpy(str2, "World!");

    strcat(str1, str2);

    printf("Concatenated String: %s\n", str1);

    free(str1);
    free(str2);
    return 0;
}
