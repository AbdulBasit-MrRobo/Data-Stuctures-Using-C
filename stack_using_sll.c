#include<stdio.h>
#include<stdlib.h>
void create(void); /*declaration of create function*/
void push(void); /*declaration of push function*/
void display(void); /*declaration of display function*/
void ask(void); /*declaration of ask function*/
void pop(void); /*declaration of pop function*/
struct node /* structure of node*/
{
	int info;
	struct node * link;
};
struct node * top=NULL; 
void main()
{
	create(); /*calling of create function*/
	ask(); /*calling of ask function*/
}
void create() /*definition of create function*/
{
	int item;
	struct node * new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("No memory available..Overflow.\n");
	}
	else
	{
		printf("Enter item :\n");
		scanf("%d",&item);
		new->info=item;
		new->link=NULL;
		top=new;
	}
	display(); /*calling of display function*/
}
void push() /*definition of push function*/
{
	int item;
	struct node * new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("No memory available..Overflow.\n");
	}
	else
	{
		printf("Enter item :\n");
		scanf("%d",&item);
		new->info=item;
		new->link=top;
		top=new;
		display(); /*calling of display function*/
		ask(); /*calling of ask function*/
	}
}
void display() /*definition of display function*/
{
	struct node * ptr;
	if(top==NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}
	}
}
void ask(void) /*definition of ask function*/
{
	int ans;
	printf("\nEnter 0 to exit \nEnter 1 to push \nEnter 2 to pop :\t");
	scanf("%d",&ans);
	if(ans==1)
	{
		push(); /*calling of push function*/
	}
	else if(ans==2)
	{
		pop(); /*calling of pop function*/
	}
	else if(ans==0)
	{
		display(); /*calling of display function*/
		exit(1); /*exiting code*/
	}
}
void pop() /*definition of pop function*/
{
	struct node * ptr;
        if(top==NULL)
	{
		printf("Empty list.\n");
	}
	else
	{
	        ptr=top;
	        top=ptr->link;
	}
	printf("%d is poped \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
