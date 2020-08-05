#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
void insertAtrear(void); /*declaration of insert at rear function*/
void deleteAtfront(void); /*declaration of delete at front function*/
void display(void); /*declaration of display function*/
void ask(void); /*declaration of ask function*/
int queue[max]; /*global declaration of queue*/
int front=-1; /*global declaration of front*/
int rear=-1; /*global declaration of rear*/
void main()
{
	ask(); /*calling of ask function*/
}
void insertAtrear() /*definition of insert at rear function*/
{
	int item;
	if((rear==(max-1) && front==0) || (front==(rear+1)))
	{
		printf("Queue Full.\n");
	}
	else
	{
		printf("Enter number to insert : ");
		scanf("%d",&item);
		if(rear==max-1)
		{
			rear=-1;
		}
		if(front==-1)
		{
			front=0;
		}
		rear++;
		queue[rear]=item;
		printf("rear = %d\t",rear+1);
		printf("front = %d\n",front+1);
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtfront() /*definition of delete at front function*/
{
	int item;
	if((front==0 && rear==-1) || (front==-1 && rear==-1))
	{
		front=-1;
		rear=-1;
		printf("Queue Empty.\n");
	}
	else
	{
		item=queue[front];
		printf("Item deleted is %d.\n",item);
		if(front==max-1)
		{	
			front=0;
		}
		else if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front++;
		}
		display(); /*calling of display function*/
	}
	ask(); /*calling of ask function*/
}
void display(void) /*definition of display function*/
{
	int i,j;
	if(front==-1 || rear==-1)
	{
		printf("Empty Queue.\n");
	}
	else
	{
		if(front<=rear)
		{
			for(i=front;i!=(rear+1);i++)
			{
				printf("%d\t",queue[i]);
			}
		}
		else
		{
			for(i=front;i<max;i++)
			{
				printf("%d\t",queue[i]);
			}
			for(j=0;j<=rear;j++)
			{
				printf("%d\t",queue[j]);
			}
		}
	}
}
void ask() /*definition of ask function*/
{
	int cond;
	printf("\nEnter  1 to insert.\nEnter 2 to delete.\nEnter 3 to exit. : ");
	scanf("%d",&cond);
	if(cond==1)
	{
		insertAtrear(); /*calling of insert at rear function*/
	}
	else if(cond==2)
	{
		deleteAtfront(); /*calling of delete at front function*/
	}
	else if(cond==3)
	{
		display(); /*calling of display function*/
		exit(1); 
	}
}
