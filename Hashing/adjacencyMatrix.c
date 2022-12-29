#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
int n;
int main()
{
	int max_edges,i,j,origin,destin,count=0;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	   max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edges %d(-1 -1 to quit):",i);
		scanf("%d %d",&origin,&destin);
		if((origin==-1) && (destin==-1))
		   break;
		if(origin >=n || destin>=n|| origin<0 ||destin<0)
		{
			printf("Invalid vertex:");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
			count++;
		}
	}
	printf("\n The Adjacency Matrix is:\n");
	for(i=0;i<n;i++)
	  printf("%4d",i);
	  
	printf("\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d",i);
		for(j=0;j<=n-1;j++)
		{
			printf("%4d",adj[i][j]);
		}
		printf("\n");
	}
	printf("Total Edges:%d",count);
	count=0;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		  if(adj[j][i]==1)
		   count++;
		   
	printf("\nIndegree of %d is %d",i,count);
	}
	
	return 0;
}
