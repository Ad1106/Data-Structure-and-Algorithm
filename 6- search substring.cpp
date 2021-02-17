#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main()
{
	clock_t start,end;
	start=clock();
    char str[80], search[10];
    int count1 = 0, count2 = 0, i, j, f,l1,l2;
 
    printf("Enter a main string:");
    gets(str);
    printf("Enter substring to be search:");
    gets(search);
    l1=strlen(str);
    l2=strlen(search);
    for (i = 0; i <=l1-l2; i++)
    {
        for (j = i; j <i+l2; j++)
        {
            f = 1;
            if (str[j] != search[j - i])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
            break;
    }
    if (f == 1)
        printf("SEARCH SUCCESSFUL! and location =%d to %d.",i,i+l2);
    else
        printf("SEARCH UNSUCCESSFUL!");
 
    	end=clock();
    double time_used=end-start;
	printf("\nTime used by CPU is %lf sec ", time_used/CLOCKS_PER_SEC);
	return 0;
}
