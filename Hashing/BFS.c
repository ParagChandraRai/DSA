#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX];
int state[MAX];
int queue[MAX],front=-1,rear=-1;
void insert_queue(int);
void BFS(int);

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

void BF_Traversal()
{
	int v;
	for(v=0;v<n;v++)
	{
		 state[v]=initial;
	}
	printf("Enter the vertex for BFS:");
	scanf("%d",&v);
	BFS(v);
}
void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v]=waiting;
	while(!isEmpty_queue())
	{
		v=delete_queue();
		printf("%d ",v);
		state[v]=visited;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && state[i]==initial)
			{
				insert_queue(i);
				state[i]=waiting;
			}
		}
	}
}
void insert_queue(int vertex)
{
	if(rear==MAX-1)
	 printf("Queue overflow");
	else
	if(front==-1)
	  front=0;
	rear++;
	queue[rear]=vertex;
	
}
int isEmpty_queue()
{
	if(front==-1 || front>rear)
	  return 1;
	  else
	  return 0;
	  
}
int delete_queue()
{
	int del_item;
	if(front==-1 ||front>rear)
	{
		printf("Queue underflow");
		exit(1);
	}
	del_item=queue[front];
	front++;
	return del_item;
}
int main()
{
	create_graph();
	BF_Traversal();
}
/*
Enter the number of vertices:5
Enter edges 0(-1 -1 to quit):0
1
Enter edges 1(-1 -1 to quit):0
2
Enter edges 2(-1 -1 to quit):2
3
Enter edges 3(-1 -1 to quit):3
4
Enter edges 4(-1 -1 to quit):-1
-1

 The Adjacency Matrix is:
   0   1   1   0   0
   0   0   0   0   0
   0   0   0   1   0
   0   0   0   0   1
   0   0   0   0   0
Enter the starting vertex for BFS:0
0 1 2 3 4
*/
