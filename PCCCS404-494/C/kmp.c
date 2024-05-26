#include <stdio.h>
#include <string.h>

void preprocess(char needle[], int len, int lps[]) {
    int p = 0, i = 1;

    while (i < len) {
        if (needle[p] == needle[i]) {
            lps[i] = p + 1;
            ++p;
            ++i;
        } else if (p == 0) {
            lps[i] = 0;
            ++i;
        } else {
            p = lps[p - 1];
        }
    }
}

int strStr(char *haystack, char *needle) {
    int hlen, nlen;
    if (0 == (hlen = strlen(haystack)) || 0 == (nlen = strlen(needle))) {
        return 0;
    }

    int lps[nlen];
    preprocess(needle, nlen, lps);

    int i = 0, j = 0;
    while (i < hlen) {
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            if (j == 0) {
                ++i;
            } else {
                j = lps[j - 1];
            }
        }

        if (j == nlen) {
            return i - nlen;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        printf("at: %d\n", strStr(argv[1], argv[2]));
    }
    return 0;
}
