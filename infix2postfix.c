#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char infix[100],postfix[100];
int size=100,top=-1;
char stack[100];
void push(char);
char pop(void);
void main()
{
	int i,j=0,x;
	printf("Enter the Infix expression :");
	gets(infix);
	push(stack,top,size);
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(isalnum(infix[i]))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i]==')')
		{
			x=pop();
			postfix[i]=x;
		}
		else
		{
			
		}
	}
}
}
