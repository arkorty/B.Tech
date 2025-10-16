#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {"int", "if", "then", "else", "endif", "while", "do", "enddo", "print"};

int isKeyword(char *word) {
    for (int i = 0; i < 9; i++)
        if (strcmp(keywords[i], word) == 0)
            return 1;
    return 0;
}

int main(int argc, char **argv) {
    char ch, buffer[20];
    FILE *fp;
    int i = 0;
    
    if (argc != 2) {
        printf("Usage: %s main.cp\n", argv[0]);
        return 0;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        // Ignore comments
        if (ch == '/' && (ch = fgetc(fp)) == '*') {
            while (fgetc(fp) != '*' || fgetc(fp) != '/');
            continue;
        }

        if (isalnum(ch)) {
            buffer[i++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t' || ispunct(ch)) && i != 0) {
            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("<KEYWORD, %s>\n", buffer);
            else if (isdigit(buffer[0]))
                printf("<NUMBER, %s>\n", buffer);
            else
                printf("<IDENTIFIER, %s>\n", buffer);
        }

        if (strchr("+-*/=<>(){};[],", ch))
            printf("<OPERATOR, %c>\n", ch);
    }

    fclose(fp);
    return 0;
}
