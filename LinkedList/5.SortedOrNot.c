//1.write a program to check whether linked list is sorted or not

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
void sortedornot()
{
	struct node *ptr;
	ptr=start;
	int x=-65536;
	while(ptr!=NULL)
	{
		if(ptr->data< x)
		  {
		  	printf("\nLinked is not Sorted:");
		  	return;
		  }
		  
		x=ptr->data;
		ptr=ptr->next;
	
	}
	printf("\nLinked List is Sorted:");
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
	int choice,item;
	while(1)
	{
		printf("\n1.Create");
		printf("\n2.Dispaly");
		printf("\n3.Sorted or not:");
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
				sortedornot();
				/*if(sortedornot())
			      printf("\nLinked List is Sorted.");
			    else
			      printf("\nLinked List is not Sorted. ");*/
			  break;
			case 4:
			exit(0);
			
		}
	}
}
