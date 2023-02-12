//Write a program that creates a singly linked list. 
//Use a function isSorted that returns 1 if the list is 
//sorted and 0 otherwise.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL;
int count=0;
struct node *create(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	printf("Enter -1 to End:");
	printf("Enter data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		count++;
		new_node=(struct node*)malloc(sizeof(struct node));
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
void display()
{
	struct node *ptr;
	ptr=start;
	
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d ",count);
}
int isSorted(struct node *start)
{
	struct node *ptr;
	ptr=start;
	int x=-65536;
	
	while(ptr!=NULL)
	{
		if(ptr->data < x)
		  return 0;
		  
		x=ptr->data;
		ptr=ptr->next;
	}
	return 1;

}
int main()
{
	int choice,n;
	while(1)
	{
		printf("\n1.Create");
		printf("\n2.Display");
		printf("\n3.Print Nth node from last");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=create(start);
				break;
			case 2:
				display();
				break;
			case 3:
				if(isSorted(start))
				 printf("List is Sorted:");
				else
				printf("List is not Sorted:");
			case 4:
				exit(0);
		}
	}
}
