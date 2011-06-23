/* regular definitions */
digit [0-9]
number {digit}+(\.{digit}+)?(E[+-]+{digit}+)?

/* token rules */
%%
{number}  { printf("%s", yytext); }
"+"       { printf("+"); } 
"-"       { printf("-"); } 
"*"       { printf("*"); } 
"/"       { printf("/"); } 
[\n]      { printf("=?\n"); }
[ \t]     {}
.         { printf("unknow input"); }
%%

/* helper functions */
  // none here, move along
