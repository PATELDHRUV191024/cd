#include<stdio.h>
#include<string.h>

int main()
{
    char stack[20], ip[20], opt[10][10], ter[10];
    int i,j,k,n,top=0,row,col;
    int len;

    for(i=0;i<20;i++)
    {
        stack[i]='\0';
        ip[i]='\0';
    }

    printf("Enter number of terminals: ");
    scanf("%d",&n);

    printf("Enter the terminals: ");
    scanf("%s",ter);

    printf("\nEnter the operator precedence table values:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter value for %c %c : ",ter[i],ter[j]);
            scanf(" %c",&opt[i][j]);
        }
    }

    printf("\nOperator Precedence Table:\n");

    printf("\t");
    for(i=0;i<n;i++)
        printf("%c\t",ter[i]);

    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("%c\t",ter[i]);
        for(j=0;j<n;j++)
        {
            printf("%c\t",opt[i][j]);
        }
        printf("\n");
    }

    stack[top]='$';

    printf("\nEnter input string (end with $): ");
    scanf("%s",ip);

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    len=strlen(ip);
    i=0;

    while(i<=len)
    {
        for(k=0;k<n;k++)
        {
            if(stack[top]==ter[k])
                row=k;

            if(ip[i]==ter[k])
                col=k;
        }

        if(stack[top]=='$' && ip[i]=='$')
        {
            printf("\nString Accepted\n");
            break;
        }

        else if(opt[row][col]=='<' || opt[row][col]=='=')
        {
            stack[++top]=ip[i];
            printf("%s\t\t%s\t\tShift %c\n",stack,ip,ip[i]);
            i++;
        }

        else if(opt[row][col]=='>')
        {
            while(stack[top]!='<' && top>0)
                top--;

            printf("%s\t\t%s\t\tReduce\n",stack,ip);
        }

        else
        {
            printf("\nString not accepted\n");
            break;
        }
    }

    return 0;
}