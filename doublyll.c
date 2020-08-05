#include<stdio.h>
#include<stdlib.h>
void create(void); /*declaration of create function*/
void insertAtfirst(void); /*declaration of insert at first function*/
void insertAtend(void); /*declaration of insert at end function*/
void display(void); /*declaration of display function*/
void revdisplay(void); /*declaration of reverse display function*/
void ask(void); /*declaration of ask function*/
void deleteAtend(void); /*declaration of delete at end function*/
void deleteAtmid(); /*definition of delete at mid function*/
void deleteAtfirst(); /*definition of delete at first function*/
struct node /* structure of node*/
{
	int info;
	struct node * next;
	struct node * prev;
};
struct node * start=NULL; /*globally declaring start*/
struct node * last=NULL; /*globally declaring last*/
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
		new->next=NULL;
		new->prev=NULL;
		start=new;
		last=new;
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
		new->next=start;
		new->prev=NULL;
		start->prev=new;
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
			ptr=ptr->next;
		}
	}
}
void revdisplay() /*definition of reverse display function*/
{
	struct node * ptr;
	if(last==NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		ptr=last;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->prev;
		}
	}
	ask();
}
void ask(void) /*definition of ask function*/
{
	int ans;
	printf("\nEnter 0 to exit \nEnter 1 to insert item at start of the link list \nEnter 2 to reverse display the link list\nEnter 3 to insert item at end of the link list\nEnter 4 to delete item at end of the link list\nEnter 5 to delete item at mid of the link list\nEnter 6 to delete item at start of the link list :\t");
	scanf("%d",&ans);
	if(ans==1)
	{
		insertAtfirst(); /*calling of insert at first function*/
	}
	else if(ans==2)
	{
		revdisplay(); /*calling of reverse display function*/
	}
	else if(ans==3)
	{
		insertAtend(); /*calling of insert at end function*/
	}
	else if(ans==4)
	{
		deleteAtend(); /*calling of delete at end function*/
	}
	else if(ans==5)
	{
		deleteAtmid(); /*calling of delete at first function*/
	}
	else if(ans==6)
	{
		deleteAtfirst(); /*calling of delete at end function*/
	}
	/*else if(ans==7)
	{
		deleteAtmid(); /*calling of delete at mid function
	}*/
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
		new->next=NULL;
		new->prev=last;
		last->next=new;
		last=new;
		display(); /*calling of display function*/
		ask(); /*calling of ask function*/
	}
}
void deleteAtend() /*definition of delete at end function*/
{
	struct node * ptr;
	struct node * save;
    if(last==NULL)
	{
		printf("Empty list.\n");
	}
	else
	{
	     ptr=last;
	     (ptr->prev)->next=NULL;
	     last=last->prev;
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
	     while(ptr->info!=item && ptr!=last)
	     {
	        save=ptr;
	        ptr=ptr->next;    
	     }
	     save->next=ptr->next;
	     (ptr->next)->prev=save;
	}
	printf("%d is deleted \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
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
	        start=ptr->next;
	        start->prev=NULL;
	}
	printf("%d is deleted \n",ptr->info);
	free(ptr);
	display(); /*calling of display function*/
	ask(); /*calling of ask function*/
}
