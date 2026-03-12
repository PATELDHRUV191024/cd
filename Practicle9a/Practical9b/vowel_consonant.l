%{
#include <stdio.h>

int vowel_count = 0;
int consonant_count = 0;
%}

%option noyywrap

%%
[aAeEiIoOuU]        { vowel_count++; }      /* Count vowels */
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]  { consonant_count++; }  /* Count consonants */
\n                  { return 0; }          /* Stop on newline */
.                   ;                      /* Ignore other characters */
%%

int main()
{
    printf("Enter a string: ");
    yylex();

    printf("\nNumber of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);

    return 0;
}