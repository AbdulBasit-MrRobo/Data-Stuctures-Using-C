#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertAtfront(void); /*declaration of insert at front function*/
void insertAtrear(void); /*declaration of insert at rear function*/
void deleteAtfront(void); /*declaration of delete at front function*/
void deleteAtrear(void); /*declaration of delete at rear function*/
void display(void); /*declaration of display function*/
void ask(void); /*declaration of ask function*/
struct node /* structure of node*/
{
	int info;
	struct node * link;
};

struct node * front=NULL; /*globally declaring front*/
struct node * rear=NULL; /*globally declaring rear*/
void ask() /*definition of ask function*/
{
	int cond;
	printf("\nEnter  1 to insert at front.\nEnter 2 to insert at rear.\nEnter 3 to delete at front.\nEnter 4 to delete at rear.\nEnter 5 to exit. : ");
	scanf("%d",&cond);
	if(cond==1)
	{
		insertAtfront(); /*calling of insert at front function*/
	}
	else if(cond==2)
	{
		insertAtrear(); /*calling of insert at rear function*/
	}
	else if(cond==3)
	{
		deleteAtfront(); /*calling of delete at front function*/
	}
	else if(cond==4)
	{
		deleteAtrear(); /*calling of delete at rear function*/
	}
	else if(cond==5)
	{
		display(); /*calling of display function*/
		exit(1);
	}
}
void insertAtrear() /*definition of insert at rear function*/
{
	int item;
	struct node * new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("No memory available..Queue Full.\n");
	}
	else
	{
		printf("Enter item :\n");
		scanf("%d",&item);
		new->info=item;
		new->link=NULL;
		rear->link=new;
		rear=new;
	}
	if(front==NULL)
	{
		front=new;
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void insertAtfront() /*definition of insert at front function*/
{
	int item;
	struct node * new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("No memory available..Queue Full.\n");
	}
	else
	{
		printf("Enter item :\n");
		scanf("%d",&item);
		new->info=item;
		new->link=front;
		front=new;
	}
	if(rear==NULL)
	{
		rear=new;
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtfront() /*definition of delete at front function*/
{
	int item;
	if(front==NULL)
	{
		printf("Queue is empty.\n");
	}
	else if(front==rear)
	{
		struct node * ptr;
		ptr=front;
		item=ptr->info;
		printf("Item deleted is %d.\n",item);
		free(ptr);
		front=NULL;
		rear=NULL;
	}
	else
	{
		struct node * ptr;
		ptr=front;
		item=ptr->info;
		front=ptr->link;
		printf("Item deleted is %d.\n",item);
		free(ptr);
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtrear() /*definition of delete at rear function*/
{
	int item;
	if(rear==NULL)
	{
		printf("Queue is empty.\n");
	}
	else if(rear==front)
	{
		struct node * ptr;
		ptr=rear;
		item=ptr->info;
		printf("Item deleted is %d.\n",item);
		free(ptr);
		front=NULL;
		rear=NULL;
	}
	else
	{
		struct node * ptr;
		ptr=front;
		while(ptr->link!=rear)
		{
			ptr=ptr->link;
		}
		item=rear->info;
		printf("Item deleted is %d.\n",item);
		free(rear);
		rear=ptr;
		rear->link=NULL;
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void display() /*definition of display function*/
{
	struct node * ptr;
	if(front==NULL && rear==NULL)
	{
		return;
	}
	else
	{
		ptr=front;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}
	}
}
void main()
{
	ask(); /*calling of ask function*/
}
