#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int a;
    scanf("%d", &a);
    printf("Enter a positive integer: ");
    int b;
    scanf("%d", &b);
    while (--b != 0) {
        a = a / 10;
    }
    a = a - (a / 10) * 10;
    printf("%d\n", a);
    return 0;
}
