#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int start,int mid,int end)
{
	int n1,n2,l[30],r[30],i,j,k,temp[100],p;
		
		n1=mid-start;
		n2=end-mid-1;
		for(i=0;i<=n1;i++)
		l[i]=a[i+start];
		for(j=0;j<=n2;j++)
		r[j]=a[j+mid+1];
	    for(k=0,i=0,j=0;i<=n1 && j<=n2;k++)
     	{
		   if(l[i]<=r[j])
		   {
		   	temp[k]=l[i];
		   	i++;
		   }
		   else
		   {
		   	temp[k]=r[j];
		   	j++;
		   }
	    }
	    while(i<=n1)
	    temp[k++]=l[i++];
	    while(j<=n2)
	    temp[k++]=r[j++];
	    
	    for(i=start,p=0;i<=end;i++,p++)
	    a[i]=temp[p];
}
void broke(int a[],int start,int end)
{

		if(start<end)
	{
		int mid=(start+end)/2;
		//printf("%d\n",mid);
		broke(a,start,mid);
		broke(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
int main()
{
	clock_t start,end;
	start=clock();
	int n;
	printf("Enterthe value of n");
	scanf("%d",&n);
	int a[n],i;
	
	for(i=0;i<n;i++)
	{
	
	a[i]=rand();

	}
	printf("Our Randon numbers are --\n");
	for(i=0;i<n;i++)
	{
		printf("%d   ", a[i]);
	}
	broke(a,0,n-1);
	printf("\nSorted array : \n");
	for(i=0;i<n;i++)
	printf("%d   ",a[i]);
	end=clock();
    double time_used=end-start;
	printf("\nTime used by CPU is %lf sec ", time_used/CLOCKS_PER_SEC);
	return 0;
}
