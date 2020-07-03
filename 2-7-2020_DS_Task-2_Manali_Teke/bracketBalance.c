#include <stdio.h>

int top= -1;
char stack[100];

void push(c)
{
    stack[++top] = c;
}

void pop()
{ --top;}

int main()
{
    char s[100];
    int i;

    printf("Enter the figure\n");
    scanf("%s",&s);

    for (i=0; s[i]!=0; i++)
    {
            if ( s[i]=='(')
            {
                push(s[i]);
            }
            else if( s[i]== ')')
            {
                pop();
            }
            
      }
 //balance_condition
 if (top==-1)
        printf("Balanced");

    else
        printf("Not Balanced ");
}