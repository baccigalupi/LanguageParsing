%option noyywrap
%{
/* Lexer example using a overdone c++ class for managing both tokens and logic */
#include "1_simple_calculator.cpp"

using namespace simple_calculator;
Queue token_queue;
Token token;

%}

/* regular definitions */
digit [0-9]
number {digit}+(\.{digit}+)?(E[+-]+{digit}+)?

/* token rules */
%%
{number}  { printf("%s", yytext); token = Token(SC_NUMBER, yytext); token_queue.append(token); }
"+"       { printf("+"); token = Token(SC_PLUS); token_queue.append(token); } 
"-"       { printf("-"); token = Token(SC_MINUS); token_queue.append(token); } 
"*"       { printf("*"); token = Token(SC_TIMES); token_queue.append(token);} 
"/"       { printf("/"); token = Token(SC_DIVIDE); token_queue.append(token);} 
[\n]      { printf("=\n"); printf("%f\n\n", token_queue.calculate()); }
[ \t]     {}
.         { printf("unknow input"); }
%%

/* helper functions */
int main(void) { 
  yylex();
  return 0;
}
