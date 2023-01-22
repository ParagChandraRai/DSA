#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
#define finished 3
int n;
int adj[MAX][MAX];
void create_graph();
int state[MAX];
void DF_Traversal();
void DFS(int v);
int main()
{
	create_graph();
	DF_Traversal();
	return 0;
}
void DF_Traversal()
{
	int v;
	for(v=0;v<n;v++)
	{
		 state[v]=initial;
	}
	printf("Enter the starting vertex of Depth first search:\n");
	scanf("%d",&v);
	DFS(v);
	for(v=0;v<n;v++)
	{
		if(state[v]==initial)
		  DFS(v);
	}
	printf("\n");
}
void DFS(int v)
{
	int i;
	printf("%d ",v);
	state[v]=visited;
	for(i=0;i<n;i++)
	{
		if(adj[v][i]==1 && state[i]==initial)
		    DFS(i);
	}
	state[v]=finished;
	
}
void create_graph()
{
	int j,i,max_edges,origin,destin;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	max_edges=n*(n-1);
	
	for(i=0;i<max_edges;i++)
	{
		printf("Enter edges %d(-1 -1 to quit):",i);
		scanf("%d %d",&origin,&destin);
		if((origin==-1) && (destin==-1))
		   break;
		if(origin >n || destin>n|| origin<0 ||destin<0)
		{
			printf("Invalid vertex:");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}
		printf("\n The Adjacency Matrix is:\n");
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%4d",adj[i][j]);
		}
		printf("\n");
	}
	
}
