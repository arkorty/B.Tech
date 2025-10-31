### **1️⃣ Lexical Analyzer (C Program)**

```c
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

int main() {
    char ch, buffer[20];
    FILE *fp;
    int i = 0;
    fp = fopen("input.txt", "r");
    if (!fp) return 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) buffer[i++] = ch;
        else if ((ch == ' ' || ch == '\n' || ch == '\t' || ispunct(ch)) && i != 0) {
            buffer[i] = '\0';
            i = 0;
            if (isKeyword(buffer)) printf("<KEYWORD, %s>\n", buffer);
            else if (isdigit(buffer[0])) printf("<NUMBER, %s>\n", buffer);
            else printf("<IDENTIFIER, %s>\n", buffer);
        }
        if (strchr("+-*/=<>(){};[],", ch)) printf("<OPERATOR, %c>\n", ch);
    }
    fclose(fp);
    return 0;
}
```

**Run:**

```bash
gcc lexical_analyzer.c -o lexical
./lexical
```

---

### **2️⃣ Lexical Analyzer using LEX**

```lex
%{
#include <stdio.h>
%}

%%
"int"|"if"|"then"|"else"|"endif"|"while"|"do"|"enddo"|"print"   { printf("<KEYWORD, %s>\n", yytext); }
[0-9]+      { printf("<NUMBER, %s>\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("<IDENTIFIER, %s>\n", yytext); }
"+"|"-"|"*"|"/"|"="|"<"|">"|"=="|"<="|">="|"!="|"("|")"|";"|","|"{"|"}"   { printf("<OPERATOR, %s>\n", yytext); }
[ \t\n]+    { }
"/*"([^*]|\*+[^*/])*\*+"/"  { }
.           { }
%%

int main() { yylex(); return 0; }
```

**Run:**

```bash
lex lexical_analyzer.l
cc lex.yy.c -lfl -o lexan
./lexan < input.txt
```

---

### **3️⃣ Predictive Parser**

```c
#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = 0, i = 0;

void push(char c) { stack[++top] = c; }
void pop() { top--; }
char peek() { return stack[top]; }

int main() {
    printf("Enter input string (like id+id*id): ");
    scanf("%s", input);
    strcat(input, "$");
    push('$'); push('E');

    while (peek() != '$') {
        char X = peek(), a = input[i];
        if (X == a) { pop(); i++; }
        else if (X == 'E') { pop(); push('E'); push('T'); printf("E->TE'\n"); }
        else { printf("Error\n"); return 0; }
    }
    printf("Accepted\n");
}
```

**Run:**

```bash
gcc predictive_parser.c -o parser
./parser
```

---

### **4️⃣ YACC – Abstract Syntax Tree**

`calc.y`

```yacc
%{
#include <stdio.h>
#include <stdlib.h>
typedef struct node{char *t;struct node *l,*r;}Node;
Node* m(char*t,Node*l,Node*r){Node*n=malloc(sizeof(Node));n->t=t;n->l=l;n->r=r;return n;}
void p(Node*r,int d){if(!r)return;p(r->r,d+1);for(int i=0;i<d;i++)printf("   ");printf("%s\n",r->t);p(r->l,d+1);}
Node*root;
%}
%token ID NUM
%left '+' '-'
%left '*' '/'
%%
e: e'+'e {$$=m("+",$1,$3);root=$$;}
 | e'-'e {$$=m("-",$1,$3);root=$$;}
 | e'*'e {$$=m("*",$1,$3);root=$$;}
 | e'/'e {$$=m("/",$1,$3);root=$$;}
 | '('e')' {$$=$2;}
 | ID {$$=m("ID",0,0);}
 | NUM {$$=m("NUM",0,0);}
 ;
%%
int main(){yyparse();p(root,0);}
int yyerror(){printf("error\n");return 0;}
```

`calc.l`

```lex
%{
#include "y.tab.h"
%}
%%
[0-9]+ {return NUM;}
[a-zA-Z]+ {return ID;}
[+\-*/() \t\n] {return yytext[0];}
%%
int yywrap(){return 1;}
```

**Run:**

```bash
lex calc.l
yacc -d calc.y
cc lex.yy.c y.tab.c -ll -ly -o calc
./calc
```

---

### **5️⃣ LALR Parser**

`lalr_parser.y`

```yacc
%{
#include <stdio.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
E : E'+'E {printf("E->E+E\n");}
  | E'-'E {printf("E->E-E\n");}
  | E'*'E {printf("E->E*E\n");}
  | E'/'E {printf("E->E/E\n");}
  | '('E')' {printf("E->(E)\n");}
  | NUM {printf("E->NUM\n");}
  ;
%%
int main(){yyparse();printf("Parsing done\n");}
int yyerror(){printf("Error\n");return 0;}
```

`lalr_lexer.l`

```lex
%{
#include "y.tab.h"
%}
%%
[0-9]+ {return NUM;}
[+\-*/()] {return yytext[0];}
[ \t\n] ;
%%
int yywrap(){return 1;}
```

**Run:**

```bash
lex lalr_lexer.l
yacc -d lalr_parser.y
cc lex.yy.c y.tab.c -ll -ly -o lalr
./lalr
```

---

### **6️⃣ Code Generator**

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[50];
int t = 1;

void gen(char op, char a, char b) {
    printf("LOAD #%c, R0\n", a);
    if(op=='+')printf("ADD #%c, R0\n",b);
    if(op=='-')printf("SUB #%c, R0\n",b);
    if(op=='*')printf("MUL #%c, R0\n",b);
    if(op=='/')printf("DIV #%c, R0\n",b);
    printf("STORE R0, T%d\n\n",t++);
}

int main(){
    printf("Enter expr: ");
    scanf("%s",expr);
    for(int i=0;i<strlen(expr);i++)
        if(isalnum(expr[i])&&strchr("+-*/",expr[i+1])){
            gen(expr[i+1],expr[i],expr[i+2]);
            i+=2;
        }
    printf("STOP\n");
}
```

**Run:**

```bash
gcc code_generator.c -o codegen
./codegen
```

---

### **7️⃣ Balanced Parentheses (LEX + YACC)**

`balanced.y`

```yacc
%{
#include <stdio.h>
%}
%token OPEN CLOSE
%%
S : /*empty*/ | S P ;
P : '(' S ')' {printf("Matched ()\n");} ;
%%
int main(){yyparse();printf("Balanced\n");}
int yyerror(){printf("Unbalanced\n");return 0;}
```

`balanced.l`

```lex
%{
#include "y.tab.h"
%}
%%
"(" {return OPEN;}
")" {return CLOSE;}
[ \t\n] ;
%%
int yywrap(){return 1;}
```

**Run:**

```bash
lex balanced.l
yacc -d balanced.y
cc lex.yy.c y.tab.c -ll -ly -o balanced
./balanced
```
