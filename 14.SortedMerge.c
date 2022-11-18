#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *insert1(struct node *start,int data);
void display(struct node *start);
struct node *create(struct node *start);
void merge(struct node *p1,struct node *p2);
int main()
{
	struct node *start1=NULL,*start2=NULL;
	printf("Enter the list 1 value\n");
	start1=create(start1);
	printf("Enter the list 2 value\n");
	start2=create(start2);
	printf("List 1 is:\n");
	display(start1);
	printf("List 2 is:\n");
	display(start2);
	merge(start1,start2);
}
struct node *create(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("Enter -1 to End:");
	printf("Enter data:");
	scanf("%d",&num);
	
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
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
	printf("\n");
}
void merge(struct node *p1,struct node *p2)
{
	struct node *start3;
	start3=NULL;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data < p2->data)
		{
			start3=insert1(start3,p1->data);
			p1=p1->next;
		}
		else if(p1->data > p2->data)
		{
			start3=insert1(start3,p2->data);
			p2=p2->next;
		}
		else if(p1->data==p2->data)
		{
           start3=insert1(start3,p2->data);
			p2=p2->next;
            p1=p1->next;			
		}
	}
	while(p1!=NULL)
	{
	 start3=insert1(start3,p1->data);
	 p1=p1->next;
	}
	while(p2!=NULL)
	{
		start3=insert1(start3,p2->data);
		p2=p2->next;
		
	}
	printf("\nAfter merging...\n");
	display(start3);
	
}
struct node *insert1(struct node *start,int data)
{
	struct node *new_node,*ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
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
	return start;
}
