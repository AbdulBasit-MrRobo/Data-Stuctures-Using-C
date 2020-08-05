#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void quicksort(int [],int ,int); /*declaration of quicksort function*/
int partition(int [],int ,int); /*declaration of partition function*/
void display(int [],int); /*declaration of display function*/
void swap(int *,int *); /*declaration of swap function*/
void main()
{
	int i,start=0,end,len;
	printf("Enter number of elements :\n");
	scanf("%d",&len);
	int data[len];
	end=len;
	printf("Enter random numbers :\n");
	for(i=0;i<end;i++)
	{
		scanf("%d",&data[i]);
	}
	display(data,len); /*calling of display function*/
	quicksort(data,start,end); /*calling of quicksort function*/
	display(data,len); /*calling of display function*/
}
void quicksort(int a[],int start,int end) /*definition of quicksort function*/
{
	int PI;
	if(start<end)
	{
		PI=partition(a,start,end); /*calling of partition function*/
		quicksort(a,start,PI-1); /*recursive call of quicksort function*/
		quicksort(a,PI+1,end); /*recursive call of quicksort function*/
	}
}
int partition(int a[],int start,int end) /*definition of partition function*/
{
	int i;
	int PI=start;
	int pivot=a[end];
	for(i=start;i<=end-1;i++)
	{
		if(a[i]<pivot)
		{
			swap(&a[i],&a[PI]); /*calling of swap function*/
			PI++;
		}
	}
	swap(&a[PI],&a[end]); /*calling of swap function*/
	return PI;
}
void swap(int *a,int *b) /*definition of swap function*/
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int a[],int len) /*definition of display function*/
{
	int i;
	printf("\n");
	for(i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
}
