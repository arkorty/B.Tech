#include <stdio.h>
#include <stdbool.h>

int power(int b, int e) {
    int p = 1;

    for (int i = 0; i < e; i++) {
        p = p * b;
    }

    return p;
}

bool is_armstrong(int n) {
    int s = 0;
    int l = 0;
    int c1 = n;
    int c2 = n;

    // get no of digits
    while (c1 != 0) {
        l = l + 1;
        c1 = c1 / 10;
    }

    // get sum of digits raised to the power of no of digits
    while (c2 != 0) {
        int d = c2 % 10;
        s = s + power(d, l);

        c2 = c2 / 10;
    }

    return s == n;
}

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    printf("%d %s an Armstrong number\n", n, is_armstrong(n) ? "is" : "is not");
}