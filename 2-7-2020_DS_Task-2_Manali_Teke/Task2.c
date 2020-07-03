#include<stdio.h>
#include<string.h>
int main()
{
    char s[100], stack[100];
    int top= -1;
    
    printf("\nEnter brackets:\n ");
    gets(s);
    
    
    for(int i=0; i< strlen(s); i++)
    {
        if(s[i]=='(')
        {
            
            stack [++top] = i; //push
        }
        else if(s[i]==')')
        {
            --top; //pop
        }
    }
    

    if(top==-1)
    {
        printf("BALANCED");
    }
    else
    {
        printf("NOT BALANCED");
    }
    
}