// Check time complexity in selection sort

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int n,z,d;
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
	}; 
	printf("\nEnter choise : 1: Selection Sort    2: Bobble Sort    3: Insertion sort\n");
	scanf("%d",&z);
	switch(z)
	{
		case 1:
	{
		printf("Selection sort selected");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
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
	break;
    }
    case 2:
    	{
    		printf("Bubble sort selected");
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
	break;
		}
		case 3:
			{
				printf("Insertion sort selected");
					for(i=1;i<n-1;i++)
					{
						for(d=i;d>0;d--)
						{
							if(a[d-1]>a[d])
							{
								t=a[d-1];
								a[d-1]=a[d];
								a[d]=t;
							}
						}
					}
	printf("\n\nSorted elements are : \n");
	for(i=0;i<n;i++)
	printf("%d   ",a[i]);
	end=clock();
	double time_used=end-start;
	printf("\nTime used by CPU is %lf sec ", time_used/CLOCKS_PER_SEC);
	break;
			}
		}
	return 0;
}
