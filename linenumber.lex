%{
#include <stdio.h>

int line_number = 1;   /* initialize line number */
%}

%%

^.*\n    { printf("%5d %s", line_number++, yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    extern FILE *yyin;

    yyin = fopen("input.txt","r");

    if(yyin == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    yylex();

    fclose(yyin);
    return 0;
}