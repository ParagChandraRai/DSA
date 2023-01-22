#include<stdio.h>
#define MAX 100
#define TEMP 0
#define PREM 1
#define infinity 9999
#define NIL -1
int n;
int adj[MAX][MAX];
int pre[MAX];
int pathlength[MAX];
int status[MAX];


void create_graph()
{
	int wt,j,i,max_edges,origin,destin;
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
			printf("Enter the weight:");
		    scanf("%d",&wt);
			adj[origin][destin]=wt;
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
void Dijkstra(int s)
{
	int i,current;
	for(i=0;i<n;i++)
	{
		pre[i]=NIL;
		pathlength[i]=infinity;
		status[i]=TEMP;
	}
	pathlength[s]=0;
	while(1)
	{
		current=min_temp();
		if(current==NIL)
		   return;
		status[current]=PREM;
		for(i=0;i<n;i++)
		{
			if(adj[current][i]!=0 && status[i]==TEMP)
			{
				if(pathlength[current]+adj[current][i]<pathlength[i])
				{
					pre[i]=current;
					pathlength[i]=pathlength[current]+adj[current][i];
				}
			}
		}
	}
}
int min_temp()
{
	int i;
	int min=infinity;
	int  k=NIL;
	for(i=0;i<n;i++)
	{
		if(status[i]==TEMP && pathlength[i]<min)
		{
			min=pathlength[i];
			k=i;
		}
	}
	return k;
}
void findpath(int s,int v)
{
	int i,u,j;
	int path[MAX];
	int shortdist=0;
	int count=0;
   int adj1[MAX][MAX]={0};
	while(v!=s)
	{
		count++;
		path[count]=v;
		u=pre[v];
		adj1[u][v]=adj[u][v];////
		shortdist+=adj[u][v];
		v=u;
	}
	
   	printf("\n The Adjacency Matrix is:\n");
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%4d",adj1[i][j]);
		}
		printf("\n");
	}	

	count++;
	path[count]=s;
	printf("Shortest path is:");
	for(i=count;i>=1;i--)
	{
		
		printf("%d ",path[i]);
	}
	printf("\nShortest distance is:%d\n",shortdist);
}
int main()
{
	int s,v;
	create_graph();
	printf("Enter source vertex:");
	scanf("%d",&v);
	Dijkstra(s);
	
	while(1)
	{
		printf("Enter the destination vertex(-1 to quit)");
		scanf("%d",&v);
		if(v==-1)
		  break;
		if(v<0 || v>=n)
		 printf("This vertex does not exit:");
	    else if(v==s)
		  printf("source and destination vertices are same\n");
		else if(pathlength[v]==infinity)
		 printf("There is no path from source to destination vertex\n");
		else
		  findpath(s,v);
		
	}
}
/*
Enter the number of vertices:8
Enter edges 0(-1 -1 to quit):0
1
Enter the weight:8
Enter edges 1(-1 -1 to quit):0
2
Enter the weight:2
Enter edges 2(-1 -1 to quit):0
3
Enter the weight:7
Enter edges 3(-1 -1 to quit):1
5
Enter the weight:16
Enter edges 4(-1 -1 to quit):2
0
Enter the weight:5
Enter edges 5(-1 -1 to quit):2
3
Enter the weight:4
Enter edges 6(-1 -1 to quit):2
6
Enter the weight:3
Enter edges 7(-1 -1 to quit):3
4
Enter the weight:9
Enter edges 8(-1 -1 to quit):4
0
Enter the weight:4
Enter edges 9(-1 -1 to quit):4
5
Enter the weight:5
Enter edges 10(-1 -1 to quit):4
7
Enter the weight:8
Enter edges 11(-1 -1 to quit):6
2
Enter the weight:6
Enter edges 12(-1 -1 to quit):6
3
Enter the weight:3
Enter edges 13(-1 -1 to quit):6
4
Enter the weight:4
Enter edges 14(-1 -1 to quit):7
5
Enter the weight:2
Enter edges 15(-1 -1 to quit):7
6
Enter the weight:5
Enter edges 16(-1 -1 to quit):-1
-1

 The Adjacency Matrix is:
   0   8   2   7   0   0   0   0
   0   0   0   0   0  16   0   0
   5   0   0   4   0   0   3   0
   0   0   0   0   9   0   0   0
   4   0   0   0   0   5   0   8
   0   0   0   0   0   0   0   0
   0   0   6   3   4   0   0   0
   0   0   0   0   0   2   5   0
Enter source vertex:0
Enter the destination vertex(-1 to quit)1
Shortest path is:0 1
Shortest distance is:8
Enter the destination vertex(-1 to quit)2
Shortest path is:0 2
Shortest distance is:2
Enter the destination vertex(-1 to quit)3
Shortest path is:0 2 3
Shortest distance is:6
Enter the destination vertex(-1 to quit)4
Shortest path is:0 2 6 4
Shortest distance is:9
Enter the destination vertex(-1 to quit)5
Shortest path is:0 2 6 4 5
Shortest distance is:14
Enter the destination vertex(-1 to quit)6
Shortest path is:0 2 6
Shortest distance is:5
Enter the destination vertex(-1 to quit)7
Shortest path is:0 2 6 4 7
Shortest distance is:17
Enter the destination vertex(-1 to quit)-1
*/
