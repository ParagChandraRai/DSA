//.write a program to delete Kth node from a linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL;
void create()
{
	struct node *ptr,*new_node;
	int num;
	printf("Enter -1 to End:");
	printf("\nEnter data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof (struct node));
		new_node->data=num;
		new_node->next=NULL;
		if(start==NULL)
		{
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			  ptr=ptr->next;
			  
			ptr->next=new_node;
			
		}
		printf("Enter data:");
	    scanf("%d",&num);
	}
	
}
void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void rev()
{
	struct node *p,*q,*r;
	r=NULL;
	q=NULL;
	p=start;
	
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	start=q;
}
int main()
{
	create();
	display();
	rev();
	printf("\nAfter Reversing...\n");
	display();
	
}
