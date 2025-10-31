## ⚙️ **17️⃣ Expression Evaluation (LEX + YACC)**

`eval.l`

```lex
%{
#include "y.tab.h"
%}
%%
[0-9]+  { yylval = atoi(yytext); return NUM; }
[+\-*/()\n]  { return yytext[0]; }
[ \t]+ ;
%%
int yywrap() { return 1; }
```

`eval.y`

```yacc
%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
S : E '\n' { printf("Result = %d\n", $1); return 0; }
  ;
E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | '(' E ')' { $$ = $2; }
  | NUM { $$ = $1; }
  ;
%%
int main() {
    printf("Enter expression: ");
    yyparse();
    return 0;
}
int yyerror() { printf("Invalid expression!\n"); return 0; }
```

### ▶️ **Run Commands**

```bash
lex eval.l
yacc -d eval.y
cc lex.yy.c y.tab.c -ll -ly -o eval
./eval
```

**Example Input:**

```
3+5*2
```

**Output:**

```
Result = 13
```

---

## 📘 **Compiler Design Glossary (Short + Lab-Focused)**

| Term                                  | Description                                                                                                                  |                                   |
| ------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- | --------------------------------- |
| **Compiler**                          | A program that translates high-level source code into machine code.                                                          |                                   |
| **Interpreter**                       | Executes code line-by-line without generating an executable file.                                                            |                                   |
| **Phases of Compiler**                | Lexical Analysis → Syntax Analysis → Semantic Analysis → Intermediate Code Generation → Code Optimization → Code Generation. |                                   |
| **Lexical Analysis**                  | Converts source code into tokens (keywords, identifiers, operators). Tool: **Lex / Flex**.                                   |                                   |
| **Token**                             | Smallest meaningful unit in code, e.g., `int`, `=`, `+`, `variable`.                                                         |                                   |
| **Pattern**                           | Rule describing how a token looks (e.g., regex for identifiers).                                                             |                                   |
| **Lexeme**                            | Actual substring in source that matches a token pattern.                                                                     |                                   |
| **Syntax Analysis (Parsing)**         | Checks grammar structure using CFG (Context-Free Grammar). Tool: **Yacc / Bison**.                                           |                                   |
| **Parse Tree**                        | Hierarchical structure showing how input conforms to grammar.                                                                |                                   |
| **Abstract Syntax Tree (AST)**        | Simplified parse tree used for semantic analysis.                                                                            |                                   |
| **Semantic Analysis**                 | Checks for logical consistency (type checking, undeclared variables).                                                        |                                   |
| **Intermediate Code**                 | Machine-independent representation, e.g., **Three-Address Code (TAC)**.                                                      |                                   |
| **Three Address Code (TAC)**          | Example: `t1 = a + b`; `t2 = t1 * c`.                                                                                        |                                   |
| **Code Optimization**                 | Improves efficiency of generated code without changing meaning.                                                              |                                   |
| **Code Generation**                   | Converts optimized intermediate code into target assembly or machine code.                                                   |                                   |
| **Symbol Table**                      | Stores information about identifiers (type, scope, location).                                                                |                                   |
| **Error Handling**                    | Mechanisms for detecting and recovering from syntax/semantic errors.                                                         |                                   |
| **Regular Expression**                | Defines patterns for tokens in lexical analysis.                                                                             |                                   |
| **Finite Automata (DFA/NFA)**         | Used by lexical analyzers to recognize patterns.                                                                             |                                   |
| **Context-Free Grammar (CFG)**        | Grammar defining syntax of programming languages.                                                                            |                                   |
| **Left Recursion**                    | Grammar rule like `E → E + T                                                                                                 | T`, needs removal for LL parsers. |
| **Left Factoring**                    | Technique to remove ambiguity in grammar by factoring common prefixes.                                                       |                                   |
| **LL Parser**                         | Top-down parser that reads input Left-to-right, derives Leftmost derivation.                                                 |                                   |
| **LR Parser**                         | Bottom-up parser reading input Left-to-right and constructing Rightmost derivation in reverse.                               |                                   |
| **LALR Parser**                       | Simplified version of LR parser (used in **YACC**).                                                                          |                                   |
| **Predictive Parser**                 | Type of LL(1) parser that uses a parsing table and lookahead symbol.                                                         |                                   |
| **Shift-Reduce Parsing**              | Bottom-up method used by LR parsers.                                                                                         |                                   |
| **Ambiguous Grammar**                 | Grammar that produces more than one parse tree for same input.                                                               |                                   |
| **FIRST and FOLLOW Sets**             | Used to build predictive parsing tables.                                                                                     |                                   |
| **Lex Tool Sections**                 | `%%` divides definitions, rules, and code.                                                                                   |                                   |
| **YACC Tool Sections**                | `%%` divides declarations, grammar rules, and user code.                                                                     |                                   |
| **Attribute Grammar**                 | Grammar where symbols have attributes to carry semantic info.                                                                |                                   |
| **Syntax-Directed Translation (SDT)** | Embedding semantic actions in grammar rules.                                                                                 |                                   |
| **Register Allocation**               | Mapping variables to CPU registers during code generation.                                                                   |                                   |
| **Peephole Optimization**             | Small local optimizations on consecutive instructions.                                                                       |                                   |
| **Error Recovery Methods**            | Panic mode, phrase-level, error productions, global correction.                                                              |                                   |
| **Backpatching**                      | Technique used to fill in jump addresses in code generation.                                                                 |                                   |
| **Recursive Descent Parser**          | Top-down parser with one function per non-terminal.                                                                          |                                   |
| **Handle**                            | The substring that matches the RHS of a production in bottom-up parsing.                                                     |                                   |
| **Derivation**                        | Step-by-step application of grammar rules to generate a string.                                                              |                                   |
| **Parsing Table**                     | Table used in predictive and LR parsing to decide which rule to apply.                                                       |                                   |
| **Phases Implemented in Lab**         | Lexical Analysis (Lex), Parsing (YACC), AST, Code Generation.                                                                |                                   |
