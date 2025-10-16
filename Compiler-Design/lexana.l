%{
#include <stdio.h>
%}

%%
"int"|"if"|"then"|"else"|"endif"|"while"|"do"|"enddo"|"print"   { printf("<KEYWORD, %s>\n", yytext); }
[0-9]+                                                          { printf("<NUMBER, %s>\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                                          { printf("<IDENTIFIER, %s>\n", yytext); }
"+"|"-"|"*"|"/"|"="|"<"|">"|"=="|"<="|">="|"!="|"("|")"|";"|","|"{"|"}"   { printf("<OPERATOR, %s>\n", yytext); }
[ \t\n]+                                                        { /* skip spaces */ }
"/*"([^*]|\*+[^*/])*\*+"/"                                     { /* skip comments */ }
.                                                               { /* ignore others */ }
%%

int main() {
    yylex();
    return 0;
}
