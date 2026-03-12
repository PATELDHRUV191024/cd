%{
#include <stdio.h>
#include <stdlib.h>

int tags = 0;
FILE *yyin;
%}

%%

"<"[^>]*">"   { 
                tags++; 
                printf("%s\n", yytext); 
              }

.|\n          { }

%%

int yywrap(void)
{
    return 1;
}

int main()
{
    FILE *f;
    char file[50];

    printf("Enter File Name : ");
    scanf("%s", file);

    f = fopen(file, "r");

    if(f == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    yyin = f;

    yylex();

    printf("\nNumber of html tags: %d\n", tags);

    fclose(yyin);

    return 0;
}