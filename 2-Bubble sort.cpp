// Check time complexity in selection sort

#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int main()
{
	int n;
	clock_t start,end;
	start=clock();
	printf("Enter the number of element , you want to sorted : ");
	scanf("%d",&n);
	int a[n],i,j,t;
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	printf("Our Randon numbers are --\n");
	for(i=0;i<n;i++)
	{
		printf("%d   ", a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("\n\nSorted elements are : \n");
	for(i=0;i<n;i++)
	printf("%d   ",a[i]);
	end=clock();
	double time_used=end-start;
	printf("\nTime used by CPU is %lf sec ", time_used/CLOCKS_PER_SEC);
	return 0;
}
