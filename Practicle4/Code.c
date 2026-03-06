#include<stdio.h>
#include<ctype.h>
#include<string.h>

int n;
char production[10][10];
char first[10], follow[10];

void findFirst(char c)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(production[i][0]==c)
        {
            if(!isupper(production[i][2]))
            {
                printf("%c ",production[i][2]);
            }
            else
            {
                findFirst(production[i][2]);
            }
        }
    }
}

void findFollow(char c)
{
    int i,j;
    if(production[0][0]==c)
        printf("$ ");

    for(i=0;i<n;i++)
    {
        for(j=2;j<strlen(production[i]);j++)
        {
            if(production[i][j]==c)
            {
                if(production[i][j+1]!='\0')
                {
                    findFirst(production[i][j+1]);
                }

                if(production[i][j+1]=='\0' && c!=production[i][0])
                {
                    findFollow(production[i][0]);
                }
            }
        }
    }
}

int main()
{
    int i;
    char c;

    printf("How many productions ?: ");
    scanf("%d",&n);

    printf("\nEnter %d productions in form A=B\n",n);

    for(i=0;i<n;i++)
        scanf("%s",production[i]);

    printf("\nFIRST sets\n");

    for(i=0;i<n;i++)
    {
        c=production[i][0];
        printf("First(%c) = { ",c);
        findFirst(c);
        printf("}\n");
    }

    printf("\nFOLLOW sets\n");

    for(i=0;i<n;i++)
    {
        c=production[i][0];
        printf("Follow(%c) = { ",c);
        findFollow(c);
        printf("}\n");
    }

    return 0;
}