#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TEMP 0
#define PREM 1
#define infinity 9999
#define NIL -1
struct edge{
	int u;
	int v;
};
int n;
int adj[MAX][MAX];
int adj1[MAX][MAX];
int predecessor[MAX];
int status[MAX];
int length[MAX];
void create_graph();
void maketree(int r,struct edge tree[MAX]);
void display1();
int main()
{
	int wt_tree=0,wt=0;
	int i,root;
	struct edge tree[MAX];
	create_graph();
	printf("Enter root vertex:");
	scanf("%d",&root);
	maketree(root,tree);
	printf("Edge to be included in spanning tree are:\n");
	for(i=1;i<=n-1;i++)
	{
		adj1[tree[i].u][tree[i].v]=1;
		//display1();
		wt=adj[tree[i].u][tree[i].v];
		printf("(%d)",wt);
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		wt_tree+=adj[tree[i].u][tree[i].v];
		
	}
	printf("Weight of the spanning tree is %d\n",wt_tree);
}
void display1( )
{
  int i,j;
for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%4d",adj1[i][j]);
		}
		printf("\n");
	}
}
void maketree(int r,struct edge tree[MAX])
{
	int current,i;
	int count=0;
	for(i=0;i<n;i++)
	{
		predecessor[i]=NIL;
		length[i]=infinity;
		status[i]=TEMP;
	}
	length[r]=0;
	while(1)
	{
		current=min_temp();
		if(current==NIL)
		{
			if(count==n-1)
			  return;
			else
			{
				printf("Graph is not connected:");
				exit(1);
			}
		
		}
		status[current]=PREM;
		if(current!=r)
		{
			count++;
			tree[count].u=predecessor[current];
			tree[count].v=current;
		}  
		for(i=0;i<n;i++)
		{
			if (adj[current][i]>0 && status[i]==TEMP)
			{
				if(adj[current][i]<length[i])
				{
					predecessor[i]=current;
					length[i]=adj[current][i];
				}
			}
		}
	}
}
int min_temp()
{
	int i;
	int min=infinity;
	int k=-1;
	for(i=0;i<n;i++)
	{
		if(status[i]==TEMP && length[i]<min)
		{
			min=length[i];
			k=i;
		}
	}
	return k;
}
void create_graph()
{
	int i,j,wt,edges,origin,distin;
	printf("Enter the number of vertex:");
	scanf("%d",&n);
	edges=n*(n-1);
	for(i=0;i<edges;i++)
	{
		printf("Enter the %d edges(-1 -1 to Exit)",i);
		scanf("%d%d",&origin,&distin);
		if(origin==-1||distin==-1)
		  break;
		printf("Enter the weight for this edge:");
		scanf("%d",&wt);
		if(origin>=n||origin<0||distin>=n||distin<0)
		{
			printf("Invalid");
			i--;
		}
		else
		{
			adj[origin][distin]=wt;
			adj[distin][origin]=wt;
			
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%4d",adj[i][j]);
		}
		printf("\n");
	}
}

/*Enter the number of vertex:6
Enter the 0 edges(-1 -1 to Exit)0
1
Enter the weight for this edge:5
Enter the 1 edges(-1 -1 to Exit)0
3
Enter the weight for this edge:4
Enter the 2 edges(-1 -1 to Exit)0
2
Enter the weight for this edge:6
Enter the 3 edges(-1 -1 to Exit)1
3
Enter the weight for this edge:2
Enter the 4 edges(-1 -1 to Exit)1
2
Enter the weight for this edge:1
Enter the 5 edges(-1 -1 to Exit)2
3
Enter the weight for this edge:2
Enter the 6 edges(-1 -1 to Exit)2
5
Enter the weight for this edge:3
Enter the 7 edges(-1 -1 to Exit)2
4
Enter the weight for this edge:5
Enter the 8 edges(-1 -1 to Exit)3
5
Enter the weight for this edge:4
Enter the 9 edges(-1 -1 to Exit)4
5
Enter the weight for this edge:4
Enter the 10 edges(-1 -1 to Exit)-1
-1
   0   5   6   4   0   0
   5   0   1   2   0   0
   6   1   0   2   5   3
   4   2   2   0   0   4
   0   0   5   0   0   4
   0   0   3   4   4   0
Enter root vertex:0
Edge to be included in spanning tree are:
   0   0   0   1   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
(4)0->3
   0   0   0   1   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
   0   1   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
(2)3->1
   0   0   0   1   0   0
   0   0   1   0   0   0
   0   0   0   0   0   0
   0   1   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
(1)1->2
   0   0   0   1   0   0
   0   0   1   0   0   0
   0   0   0   0   0   1
   0   1   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   0   0
(3)2->5
   0   0   0   1   0   0
   0   0   1   0   0   0
   0   0   0   0   0   1
   0   1   0   0   0   0
   0   0   0   0   0   0
   0   0   0   0   1   0
(4)5->4
Weight of the spanning tree is 14
*/
