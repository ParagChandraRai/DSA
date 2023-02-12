//1.write a program that removes all nodes that have duplicate information.

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
		printf("\nEnter data:");
	    scanf("%d",&num);
	}
	
}
struct node *RDup(struct node *start)
{
	struct node *p,*q;
	p=start;
	q=start->next;
	
	while(q->next!=NULL)
	{
		if( p->data!= q->data)
		{
			p=q;
			q=q->next;
		}
		p->next=q->next;
		free(q);
		q=p->next;
	}
	return start;
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
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Create");
		printf("\n2.Dispaly");
		printf("\n.3 Remove Duplicate:");
		printf("\n4.Exit");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				start=RDup(start);
		 	  break;
			case 4:
			exit(0);
			
		}
	}
}
