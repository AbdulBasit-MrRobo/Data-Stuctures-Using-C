#include<stdio.h>
void main()
{
	int i,n,x,h;
	printf("Enter the total number :\n"); 
	scanf("%d",&n); /*takes length of array from user*/
	int a[n+1];
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]); /*takes elements of array from user*/
	}
	printf("Enter the number to find :\n");
	scanf("%d",&x); /*takes number to find in array from user*/
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
 		{
			break;
 		}
	}
	int count=i;
	printf("Number is present at index %d\n",i); 
	printf("Enter the number to add in array :\n");
	scanf("%d",&h); /*takes number to add in previous array at index where given number was found*/
	for(i=n;i>=count;i--)
	{
		a[i+1]=a[i]; /*shifting of elements for addition of new element*/
	}
	a[count]=h; 
	printf("After addition Array is :\n");
	for(i=0;i<(n+1);i++)
	{
		printf("%d\t",a[i]); /*displays final array*/
	}
}
