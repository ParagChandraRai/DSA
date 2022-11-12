#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
void display(struct node*);
struct node *create(struct node*);
void count(struct node*);
int main()
{
	int option;
	while(1)
	{
		printf("\n1.create list");
		printf("\n2.Display");
		printf("\n3.count");
		printf("\n4.Exit");
		printf("\nEnter choice:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start=create(start);
				printf("Linked list is created");
				break;
			case 2:
				display(start);
				break;
			case 3:
				count(start);
				break;
			case 4:
				exit(0);
		}
	}
}

struct node *create(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\nEnter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			 ptr=ptr->next;
			 
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("Enter data:");
		scanf("%d",&num);
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
}
void count(struct node *start)
{
	struct node *ptr;
	ptr=start;
	int count=0;
	while(ptr!=NULL)
	{
	  count++;
		ptr=ptr->next;
	}
	printf("No of Node:%d",count);

}
