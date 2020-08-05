#include<stdio.h>
#include<stdlib.h>
void create(void); /*declaration of create function*/
void insertAtfirst(void); /*declaration of insert at first function*/
void insertAtend(void); /*declaration of insert at end function*/
void insertAtmid(void); /*declaration of insert at mid function*/
void insertsort(void); /*declaration of insert in ascending link list function*/
void display(void); /*declaration of display function*/
void ask(void); /*declaration of ask function*/
void deleteAtfirst(void); /*declaration of delete at fisrt function*/
void deleteAtend(void); /*declaration of delete at end function*/
void deleteAtmid(void); /*declaration of delete at mid function*/
struct node * find(int); /*declaration of find function*/
struct node * findsort(int); /*declaration of find function*/
struct node /* structure of node*/
{
	int info;
	struct node * link;
};
struct node * start=NULL; /*globally declaring strart*/
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
		start=new;
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
		new->info=item;
		new->link=start;
		start=new;
		display(); /*calling of display function*/
		ask(); /*calling of ask function*/
	}
}
void display() /*definition of display function*/
{
	struct node * ptr;
	if(start==NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		ptr=start;
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
	printf("\nEnter 0 to exit \nEnter 1 to insert item at start of the link list \nEnter 2 to insert item at end of the link list \nEnter 3 to insert item at middle of the link list\nEnter 4 to insert in a sorted list \nEnter 5 to delete item at start of the link list \nEnter 6 to delete item at start of the link list \nEnter 7 to delete item in the link list :\t");
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
		insertsort(); /*calling of insertsort function*/
	}else if(ans==5)
	{
		deleteAtfirst(); /*calling of delete at first function*/
	}else if(ans==6)
	{
		deleteAtend(); /*calling of delete at end function*/
	}else if(ans==7)
	{
		deleteAtmid(); /*calling of delete at mid function*/
	}
	else if(ans==0)
	{
		display(); /*calling of display function*/
		exit(1); /*exiting code*/
	}
}
void insertAtend() /*definition of insert at end function*/
{
	int item;
	struct node * new;
	struct node * ptr=start;
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
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
		display(); /*calling of display function*/
		ask(); /*calling of ask function*/
	}
}
void insertAtmid() /*deletion of insert at mid function*/
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
			display(); /*calling of display function*/
			ask(); /*calling of ask function*/
		}
	}
}
struct node * find(int num) /*definition of find function*/
{
	struct node * ptr=start;
	while(ptr->info!=num)
	{
		ptr=ptr->link;
	}
	return ptr;
}
struct node * findsort(int item) /*definition of findsort function*/
{
	struct node * ptr=start;
	struct node * save=start;
	struct node * loc;
	if(start==NULL)
	{
		loc=NULL;
	}
	else if(item<start->info)
	{
		loc=NULL;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(item>ptr->info)
			{
				save=ptr;
				ptr=ptr->link;
			}
			else
			{
				if(save->link==NULL)
				{
					loc=0;
				}
				else
				{
					loc=save;
				}
				break;
			}
		}
	}
	return loc;
}
void insertsort(void) /*definition of insertsort function*/
{
	int item;
	struct node * loc;
	printf("Enter the item to insert in sorted link list :\t");
	scanf("%d",&item);
	loc=findsort(item); /*calling of findsort function*/
	if(loc==NULL)
	{
		struct node * new;
		new=(struct node *)malloc(sizeof(struct node));
		if(new==NULL)
		{
			printf("\nOverflow");
		}
		else
		{
			new->info=item;
			new->link=start;
			start=new;
			display(); /*calling of display function*/
			ask(); /*calling of ask function*/
		}
	}
	else if(loc==0)
	{
		struct node * ptr=start;
		struct node * new;
		new=(struct node *)malloc(sizeof(struct node));
		if(new==NULL)
		{
			printf("\nOverflow");
		}
		else
		{
			new->info=item;
			new->link=NULL;
			while(ptr->link!=NULL)
			{
				ptr=ptr->link;
			}
			ptr->link=new;
			display(); /*calling of display function*/
			ask(); /*calling of ask function*/
		}
	}
	else
	{
		struct node * new;
		new=(struct node *)malloc(sizeof(struct node));
		if(new==NULL)
		{
			printf("\nOverflow");
		}
		else
		{
			new->info=item;
			new->link=loc->link;
			loc->link=new;
			display(); /*calling of display function*/
			ask(); /*calling of ask function*/
		}
	}
}
void deleteAtfirst() /*definition of delete at first function*/
{
	struct node * ptr;
        if(start==NULL)
	{
		printf("Empty list.\n");
	}
	else
	{
	        ptr=start;
	        start=ptr->link;
	}
	printf("%d is deleted \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtend() /*definition of delete at end function*/
{
	struct node * ptr;
	struct node * save;
    if(start==NULL)
	{
		printf("Empty list.\n");
	}
	else
	{
	     ptr=start;
	     while(ptr->link!=NULL)
	     {
	        save=ptr;
	        ptr=ptr->link;    
	     }
	     save->link=NULL;
	}
	printf("%d is deleted \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
void deleteAtmid() /*definition of delete at mid function*/
{
	struct node * ptr;
	struct node * save;
   if(start==NULL)
	{
		printf("Empty list.\n");
	}
	else
	{
	     int item;
	     printf("Enter the item to be deleted :");
	     scanf("%d",&item);
	     ptr=start;
	     while(ptr->info!=item)
	     {
	        save=ptr;
	        ptr=ptr->link;    
	     }
	     save->link=ptr->link;
	}
	printf("%d is deleted \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
