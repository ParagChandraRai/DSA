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
void countNonZero()
{
	struct node *ptr;
	ptr=start;
	int count=0;
	while(ptr!=NULL)
	{
		if(ptr->data > 0)
		 count++;
		ptr=ptr->next;
	}
	printf("No of Non Zero Element %d",count);
}
int main()
{
	create();
	display();
	countNonZero();
	
}
