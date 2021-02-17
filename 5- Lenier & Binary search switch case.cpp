#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main()
{
   int i, first, last, middle, n,j, search,p=0,z;
   clock_t start,end;
	start=clock();
 
  printf("Enter the number of element , you want to sorted : ");
   scanf("%d",&n);
 int array[n],t;
   printf("Enter %d integers\n", n);
 
   for(i=0;i<n;i++)
	{
		array[i]=rand();
	}
	printf("Our Random numbers are : \n");
	for(i=0;i<n;i++)
	{
		printf("%d   ",array[i]);
	}
	
	printf("Sortinhg done by selection sort");
		for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(array[i]>array[j])
			{
				t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
		}
	}
	printf("\n\nSorted elements are : ");
	for(i=0;i<n;i++)
	printf("%d   ",array[i]);
 
   printf("\nEnter value to find\n");
   scanf("%d", &search);
   
   printf("Choose 1 : Lenier search & 2 : Bubble search :  \n");
   scanf("%d",&z);
 switch(z)
 {
    case 1:
{   printf("Linear search Selected\n");
  	for(j=0;j<n;j++)
  	{
  	  if(search==array[j])
	  {printf("No. is found and position= %d\n",j+1);
	  p=1;
	  break;}		
	}
  
  if(p==0)
  printf("Number is not found in the list\n");
 end=clock();
	double time_used=end-start;
	printf("\nTime used by CPU is %lf sec ", time_used/CLOCKS_PER_SEC);
}
    case 2:
{   printf("Binary search selected");
    first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", search);
 end=clock();
	double time_used=end-start;
	printf("\nTime used by CPU is %lf sec ", time_used/CLOCKS_PER_SEC);		
}
 }  
 return 0;  
}
