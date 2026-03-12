%{
#include<stdio.h>

int sc = 0;   // space count
int wc = 0;   // word count
int lc = 0;   // line count
int cc = 0;   // character count
%}

%%

\n        { lc++; cc += yyleng; }
[ \t]     { sc++; cc += yyleng; }
[^\t\n ]+ { wc++; cc += yyleng; }

%%

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        yyin = fopen(argv[1], "r");
    }
    else
    {
        printf("Enter the input\n");
        yyin = stdin;
    }

    yylex();

    printf("The number of lines=%d\n", lc);
    printf("The number of spaces=%d\n", sc);
    printf("The number of words=%d\n", wc);
    printf("The number of characters are=%d\n", cc);

    return 0;
}

int yywrap()
{
    return 1;
}