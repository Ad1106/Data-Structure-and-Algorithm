#include<stdio.h>
#include<stdlib.h>
struct edge
{
	public:
	int s,d,w;
};
int findparent(int v , int *parent)
{
	if(parent[v] == v)
	{
		return v;
	}
	else
	return findparent(parent[v], parent);
}

void kruskals(edge *input, int n , int e)
{
	int t;
	for(int x=0;x<e;x++)
	{
		for(int y=0;y<e-1;y++)
		{
			if(input[y].w > input[y+1].w)
			{
				t=input[x].w;
				input[x].w=input[y].w;
				input[y].w=t;
				
				t=input[x].s;
				input[x].s=input[y].s;
				input[y].s=t;
				
				t=input[x].d;
				input[x].d=input[y].d;
				input[y].d=t;
			}
		}
	}
	struct edge *output = (struct edge*) malloc((n-1) * sizeof(edge));
	int *parent = (int*) malloc( n * sizeof(int));
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	int count=0,i=0;
	while(count!=n-1)
	{
		edge currentedge = input[i];
		int sp=findparent(currentedge.s,parent);
		int dp=findparent(currentedge.d,parent);
		
		if(sp!=dp)
		{
			output[count++]=currentedge;
			parent[sp]=dp;
		}
		else
		i++;
	}
	printf("In MST (By Kruskals algo), Source_vertix , Dest_vertix & Weight of edges is\n");
	for(i=0;i<n-1;i++)
	{
		if(output[i].s<output[i].d)
		printf("%d  %d  %d  \n",output[i].s,output[i].d,output[i].w);
		else
		printf("%d  %d  %d  \n",output[i].d,output[i].s,output[i].w);
	}
}

int main()
{
	int v,e;
	printf("Enter the no. of vertices and edges\n");
	scanf("%d%d",&v,&e);
	struct edge *input = (struct edge*) malloc(e * sizeof(edge));
	printf("enter the source_vertix,dest_vertix,weight\n");
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		scanf("%d%d%d",&s,&d,&w);
		input[i].s=s;
		input[i].d=d;
		input[i].w=w;
	}
	kruskals(input,v,e);
	return 0;
}
