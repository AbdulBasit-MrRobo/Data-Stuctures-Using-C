#include<stdio.h>
#include<stdlib.h>
void swap(int *,int *); /*declaration of swapping function*/
void bubble_sort(int *,int ); /*declaration of bubble sort fuction*/
void main()
{
	int n,i,j;
	printf("Enter the value of n : ");
	scanf("%d",&n); /*takes length of array from user*/
	int a[n];
	printf("Enter random %d values : ",n);
	for(i=0;i<n;i++)
 	{
   		scanf("%d",&a[i]); /*takes elements of array from user*/
 	}
 	printf("Values before sorting : ");
	for(i=0;i<n;i++)
 	{
   		printf("%d\t",a[i]); /*displaying of array before sorting*/
 	}
 	bubble_sort(a,n); /*calling of bubble sort function*/
 	printf("\nValues after sorting : ");
	for(i=0;i<n;i++)
 	{
   		printf("%d\t",a[i]); /*displaying of array after sorting*/
 	}
}
void bubble_sort(int *x,int y) /*definition of bubble sort*/
{
 	int i,j;
  	for(i=0;i<y;i++)
 	{
   		for(j=0;j<(y-i);j++)
   		{
     		if(x[j]>x[j+1])
     		{
       			swap(&x[j],&x[j+1]); /*calling of swapping function*/
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
