#include<stdio.h>
#include<stdlib.h>
void push(int *,int ,int );
void pop(int *,int ,int );
void display(int *,int ,int );
void choice(int *,int ,int );
void peep(int *,int ,int );
void change(int *,int ,int );
int isNegindex(int );
void main()
{
					int size,top=-1,insert,sc;
					printf("Enter the size :");
					scanf("%d",&size);
					int stack[size];
					choice(stack,top,size);
}
void push(int *stack,int top,int size)
{
     int i;
					printf("Enter the element :");
					for(i=0;i<=size;i++)
					{
								if(top==(size-1))
								{
								    printf("stack is FULL");
								    choice(stack,top,size);
								    break;
								}
								else 
							 {
							     top++;
					       scanf("%d",&stack[top]);
					       printf("element are :\t");
					       display(stack,top,size);
					       choice(stack,top,size);
					       break;
					   }
    }
}
void pop(int *stack,int top,int size)
{
     int i;
					if(top==-1)
					{
								    printf("stack is empty");
								    choice(stack,top,size);
					}
								else 
					{
										for(i=0;i<=size;i++)
					     {
							     top--;
					       printf("element are :\t");
					       display(stack,top,size);
					       choice(stack,top,size);
					       break;
					     }
				 }
}
void display(int *stack,int top,int size)
{
  int i;
  for(i=0;i<=top;i++)
  {
     printf("%d\t",stack[i]);
  }
  choice(stack,top,size);
}
void peep(int *stack,int top,int size)
{
  int i;
  printf("Enter the position from top : \t");
  scanf("%d",&i);
  int flag=isNegindex(i);
  if(flag==1)
  {
    if((top-i)<0)
    {
      printf("\n Position not found");
    }
    else
    {
      printf("The element on %d position is %d\n",i,stack[top-i]);
    }
  }
  else
  {
    printf("Ur position cannot be negative");
  } 
}
int isNegindex(int index)
{
 if(index<0)
 {
  return 0;
 }
 else
 {
  return 1;
 }
}
void change(int *stack,int top,int size)
{
		int i,item;
		   printf("Enter the position which is to be changed :");
		   scanf("%d",&i);
					printf("Enter the element to be replaced :");
					scanf("%d",&item);
					if(top-i<0)
					{
								    printf("stack is empty");
								    return;
								    choice(stack,top,size);
					}
					else
					{
					      stack[top-i]=item;
					      display(stack,top,size);
					      choice(stack,top,size);
					}
}
void choice(int *stack,int top ,int size)
{
 int sc;
 printf("\n Enter \n 1 for push \n 2 for pop \n 3 for display \n 4 for peep \n 5 for change \n 6 for exit :");
 scanf("%d",&sc);
 switch(sc)
					{
					     case 1 : push(stack,top,size);
					              break;
					     case 2 : pop(stack,top,size);
					              break;
					     case 3 : display(stack,top,size);
					              break;
					     case 4 : peep(stack,top,size);
					              break;
					     case 5 : change(stack,top,size);
					              break;
					     case 6 : exit(0);
					     default : printf("invalid input");
					} 
}
