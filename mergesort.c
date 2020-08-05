#include<stdio.h>
void Merge(int *,int *,int ,int *,int ); /*declaration of merge function*/
void MergeSort(int *,int ); /*declaration of merge sort function*/
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) /*definition of merge function*/
{
	int i,j,k;
	i=0; 
	j=0; 
	k=0;
    while(i<leftCount && j<rightCount) 
    {
		if(L[i]<R[j])
        { 
            A[k]=L[i];
            i++;
            k++;
        }	
	    else
        { 
            A[k]=R[j];
            j++;
        	k++;
        }
    }
	while(i<leftCount)             
    {
    	A[k]=L[i];
        i++;
        k++;
    }
	while(j<rightCount) 
    {              
    	A[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int *A,int n) /*definition of merge function*/
 {
	int mid,i,*L,*R;
	if(n<2) 
	{
	    return;
	} 
	mid=n/2;  
	L=malloc(mid); 
	R=malloc(n- mid); 
	for(i=0;i<mid;i++)
    {
	    L[i]=A[i];
	}
	for(i=mid;i<n;i++)
    {
	    R[i-mid]=A[i]; 
    }
	MergeSort(L,mid); /*recursive call of merge sort function*/ 
	MergeSort(R,n-mid);  /*recursive call of merge sort function*/
	Merge(A,L,mid,R,n-mid);  /*calling of merge function*/
}
void main() 
{  
	int i,len;
	printf("Enter the total numbers : ");
	scanf("%d",&len);
	int A[len];
	printf("Enter %d random numbers : ",len);
	for(i=0;i<len;i++)
    {   
        scanf("%d",&A[i]);
	}
	MergeSort(A,len); /*calling of merge sort function*/
	for(i=0;i<len;i++)
    {   
        printf("%d\t",A[i]);
	}
}


