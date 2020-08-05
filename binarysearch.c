#include<stdio.h>
#include<stdlib.h>
int b_search(int *,int ,int ,int ); /*declaration of binary search function*/
void swap(int *,int *); /*declaration of swapping function*/
void sort(int *,int ); /*declaration of sorting function*/
void main()
{	
	int i,length,item,loc=0;
	printf("Enter the total number :");
	scanf("%d",&length); /*takes length of array from user*/
	int data[length+1];
	printf("Enters the numbers :");
	for(i=0;i<length;i++)
	{
		scanf("%d",&data[i]); /*takes element of array from user*/
	}
	sort(data,length-1); /*calling of sorting function*/
	printf("Enter the number to find :");
	scanf("%d",&item); /*takes number to find in array*/
	loc=b_search(data,0,length,item); /*calling of binary search function*/
	if(loc!=0)
	{
		printf("Data Found at %d\n",loc+1);
 	}
	else
 	{
  		printf("Data not Found\n");
 	}
}
int b_search(int *data,int beg,int n,int item ) /*definition of binary search function*/
{
 	int end=n-1;
 	int mid=(beg+end)/2;
 	int loc=-1;
 
 	while(beg<=end && data[mid]!=item)
 	{
  		if(item<data[mid])
  		{
   			end=mid-1;
  		}
  		else
  		{
  			beg=mid+1;
  		}
  		mid=(end+beg)/2;
 	}
  	if(data[mid]==item)
  	{
   		loc=mid;
  	}
  	else
  	{
   		loc=NULL;
  	}
  	return loc; /*returning location(index) of number to find*/
}
void sort(int *x,int y) /*definition of sorting function*/
{
 	int i,j;
  	for(i=0;i<y;i++)
 	{
   		for(j=0;j<(y-i);j++)
   		{
     		if(x[j]>x[j+1])
     		{
       			swap(&x[j],&x[j+1]); /*calling of swap function*/
     		}
   		}
 	}
}
void swap(int *x,int *y) /*definition of swapping function*/
{
 	int t;
 	t=*x;
 	*x=*y;
 	*y=t;
}

