#include <stdio.h>
#include<stdlib.h>
 #include<time.h>
int partition(int a[], int l, int h)
{
    int pivot, i, j, temp;
    if (l < h)
    {
        pivot = l;
        i = l;
        j = h;
        while (i < j) 
        {
            while (a[i] <= a[pivot] && i <= h)
            {
                i++;
            }
            while (a[j] > a[pivot] && j >= l)
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        if(i>j)
        {
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        }
    }
    return j;
}



void quicksort(int a[], int l, int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		quicksort(a, l, j - 1);
        quicksort(a, j + 1, h);
	}
}

int main()
{
	clock_t start,end;
	start=clock();
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n); 
    int a[n],i;
    for (i = 0; i < n; i++)
        a[i]=rand();
    printf("\nOur Random Numbers are \n");
	for(i=0;i<n;i++)
	printf("%d   ",a[i]);
    quicksort(a, 0, n - 1);
    printf("\nAfter applying quick sort\n");
    for (i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("\n");
 	end=clock();
	double time_used=end-start;
	printf("\nTime used by CPU for sorting %d elements is %lf sec ",n, time_used/CLOCKS_PER_SEC);
    return 0;
}
