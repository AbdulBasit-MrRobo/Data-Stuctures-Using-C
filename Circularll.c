#include<stdio.h>
#include<stdlib.h>
void create(void); /*declaration of create function*/
void insertAtfirst(void); /*declaration of insert at first function*/
void insertAtend(void); /*declaration of insert at end function*/
void insertAtmid(void); /*declaration of insert at mid function*/
void deleteAtfirst(void); /*definition of delete at first function*/
void deleteAtend(void); /*declaration of delete at end function*/
void deleteAtmid(void); /*definition of delete at mid function*/
void display(void); /*declaration of display function*/
void ask(void); /*declaration of ask function*/
struct node
{
	int info;
	struct node * link;
};
struct node * last=NULL; /*globally declaring last*/
struct node * find(int); /*declaration of find function*/
void main()
{
	char ans;
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
		last=new;
		new->link=last;
	}
	display(); /*calling of display function*/
}
void insertAtfirst() /*definition of insert at first function*/
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
		if(last==NULL)
		{
			last=new;
			new->link=last;
			new->info=item;
		}
		else
		{
		new->info=item;
		new->link=last->link;
		last->link=new;
		}
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void display() /*definition of display function*/
{
	struct node * ptr;
	if(last==NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		ptr=last->link;
		do
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}while(ptr!=last->link);
	}
}
void ask(void) /*definition of ask function*/
{
	int ans;
	printf("\nEnter 0 to exit \nEnter 1 to insert item at start of the link list \nEnter 2 to insert item at end of the link list \nEnter 3 to insert item at middle of the link list\nEnter 4 to delete at start of the link list \nEnter 5 to delete at end of the link list \nEnter 6 to delete at after number in the link list :\t");
	scanf("%d",&ans);
	if(ans==1)
	{
		insertAtfirst(); /*calling of insert at first function*/
	}
	else if(ans==2)
	{
		insertAtend(); /*calling of insert at end function*/
	}
	else if(ans==3)
	{
		insertAtmid(); /*calling of insert at mid function*/
	}
	else if(ans==4)
	{
		deleteAtfirst(); /*calling of delete at first function*/
	}
	else if(ans==5)
	{
		deleteAtend(); /*calling of delete at end function*/
	}
	else if(ans==6)
	{
		deleteAtmid(); /*calling of delete at mid function*/
	}
	else if(ans==0)
	{
		display(); /*calling of display function*/
		exit(1);
	}
}
void insertAtend() /*definition of insert at end function*/
{
	int item;
	struct node * new;
	struct node * ptr=last;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("No memory available..Overflow.\n");
	}
	else
	{
		printf("Enter item :\n");
		scanf("%d",&item);
		if(last==NULL)
		{
			last=new;
			new->link=last;
			new->info=item;
		}
		else
		{
			new->info=item;
			new->link=last->link;
			last->link=new;
			last=new;
		}
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void insertAtmid() /*definition of insert at mid function*/
{
	int item,num;
	struct node * new;
	struct node * loc;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("No memory available..Overflow.\n");
	}
	else
	{
		printf("\nEnter the number after which item is to be inserted :\t");
		scanf("%d",&num);
		loc=find(num); /*calling of find function*/
		printf("Enter item :\n");
		scanf("%d",&item);
		if(loc==NULL)
		{
			insertAtfirst(); /*calling of insert at first function*/
		}
		else
		{
			new->info=item;
			new->link=loc->link;
			loc->link=new;
		}
	}
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
struct node * find(int num) /*definition of find function*/
{
	struct node * ptr=last->link;
	while(ptr->info!=num)
	{
		ptr=ptr->link;
	}
	return ptr;
}
void deleteAtfirst() /*definition of delete at first function*/
{
	struct node * ptr;
        if(last==NULL)
	{
		printf("Empty List.\n");
	}
	else
	{
	        ptr=last->link;
	        last->link=ptr->link;
	}
	printf("%d is deleted \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtend() /*definition of delete at end function*/
{
	struct node * ptr;
	if(last==NULL)
	{
		printf("Empty List.\n");
	}
	else
	{
	     ptr=last->link;
	     while(ptr->link!=last)
	     {
	        ptr=ptr->link;    
	     }
	     ptr->link=last->link;;
	}
	printf("%d is deleted \n",last->info);
	free(last);
	last=ptr;
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtmid() /*definition of delete at mid function*/
{
	int num;
	struct node * ptr;
	struct node * loc;
		printf("\nEnter the number after which item is to be deleted :\t");
		scanf("%d",&num);
		loc=find(num); /*calling of find function*/
		if(loc==NULL)
		{
			printf("Number not found.");
		}
		else
		{
			ptr=loc->link;
			loc->link=ptr->link;
			printf("%d is deleted \n",ptr->info);
			free(ptr);
			display(); /*calling of display function*/
			ask(); /*calling of ask function*/
		}
}
