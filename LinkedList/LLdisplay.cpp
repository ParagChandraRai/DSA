#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL;
struct node *create(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("Enter -1 to end");
	printf("Enter no.");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data = num;
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
		printf("Enter data");
		scanf("%d",&num);
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("Linked List is:\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
}
struct node *sort(struct node *start)
{
	struct node *p,*q;
	int temp;
	for(p=start;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
	return start;
}
int main()
{
    start=create(start);
	display(start);
	
	start=sort(start);
	printf("After sorting..\n");
	display(start);
}
