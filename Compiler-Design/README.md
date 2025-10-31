## ⚙️ **1. Setup on Ubuntu**

### 🧰 **Install Required Packages**

Run this once:

```bash
sudo apt update
sudo apt install gcc flex bison -y
```

> 📝 `flex` = Lex tool, `bison` = YACC equivalent for Linux.

---

## 🧩 **Exercise 1 – Lexical Analyzer (C Program)**

### 📁 Files

* `lexical_analyzer.c`
* `input.txt`

### ▶️ **Commands**

```bash
gcc lexical_analyzer.c -o lexical
./lexical
```

---

## 🧩 **Exercise 2 – Lexical Analyzer using LEX**

### 📁 Files

* `lexical_analyzer.l`
* `input.txt`

### ▶️ **Commands**

```bash
lex lexical_analyzer.l
cc lex.yy.c -lfl -o lex_analyzer
./lex_analyzer < input.txt
```

---

## 🧩 **Exercise 3 – Predictive Parser (C Program)**

### 📁 Files

* `predictive_parser.c`

### ▶️ **Commands**

```bash
gcc predictive_parser.c -o parser
./parser
```

---

## 🧩 **Exercise 4 – YACC Program (Abstract Syntax Tree)**

### 📁 Files

* `calc.l`
* `calc.y`

### ▶️ **Commands**

```bash
lex calc.l
yacc -d calc.y
cc lex.yy.c y.tab.c -ll -ly -o calc
./calc
```

---

## 🧩 **Exercise 5 – LALR Parser**

### 📁 Files

* `lalr_lexer.l`
* `lalr_parser.y`

### ▶️ **Commands**

```bash
lex lalr_lexer.l
yacc -d lalr_parser.y
cc lex.yy.c y.tab.c -ll -ly -o lalr
./lalr
```

---

## 🧩 **Exercise 6 – Code Generator**

### 📁 Files

* `code_generator.c`

### ▶️ **Commands**

```bash
gcc code_generator.c -o codegen
./codegen
```

---

## 🧩 **BONUS — YACC Program to Check Balanced Parentheses**

This is a **classic viva/lab question** and very short to memorize.

### 📄 **File: `balanced.y`**

```yacc
%{
#include <stdio.h>
int yylex(void);
void yyerror(char *s);
%}

%token OPEN CLOSE

%%
S : /* empty */
  | S P
  ;
P : '(' S ')'    { printf("Matched ()\n"); }
  ;
%%

int main() {
    printf("Enter parentheses string: ");
    yyparse();
    printf("Parentheses are balanced!\n");
    return 0;
}

void yyerror(char *s) {
    printf("Unbalanced parentheses!\n");
}
```

---

### 📄 **File: `balanced.l`**

```lex
%{
#include "y.tab.h"
%}

%%
"("   { return OPEN; }
")"   { return CLOSE; }
[ \t\n] ;
.     { printf("Invalid symbol: %s\n", yytext); }
%%

int yywrap() { return 1; }
```

---

### ▶️ **Commands to Run**

```bash
lex balanced.l
yacc -d balanced.y
cc lex.yy.c y.tab.c -ll -ly -o balanced
./balanced
```

**Example Run**

```
Enter parentheses string: (()())
Matched ()
Matched ()
Matched ()
Parentheses are balanced!
```

If you type something like:

```
(()))
```

You’ll see:

```
Unbalanced parentheses!
```

---

## ✅ **Summary Table**

| Exercise | Tool       | Compile Commands                                                                   | Run                     |
| -------- | ---------- | ---------------------------------------------------------------------------------- | ----------------------- |
| 1        | GCC        | `gcc lexical_analyzer.c -o lexical`                                                | `./lexical`             |
| 2        | LEX        | `lex file.l && cc lex.yy.c -lfl -o output`                                         | `./output < input.txt>` |
| 3        | GCC        | `gcc predictive_parser.c -o parser`                                                | `./parser`              |
| 4        | LEX + YACC | `lex calc.l && yacc -d calc.y && cc lex.yy.c y.tab.c -ll -ly -o calc`              | `./calc`                |
| 5        | LEX + YACC | `lex lalr_lexer.l && yacc -d lalr_parser.y && cc lex.yy.c y.tab.c -ll -ly -o lalr` | `./lalr`                |
| 6        | GCC        | `gcc code_generator.c -o codegen`                                                  | `./codegen`             |
| Bonus    | LEX + YACC | `lex balanced.l && yacc -d balanced.y && cc lex.yy.c y.tab.c -ll -ly -o balanced`  | `./balanced`            |
