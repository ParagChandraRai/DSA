//1.write a program to print total number of occurances of a given item in linked list

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
void countOcc(int item)
{
	struct node *ptr;
	ptr=start;
	int count=0;
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		  count++;
		ptr=ptr->next;
	}
	printf("%d occurs at %d times:",item,count);
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
		printf("\n.3 count Occurance::");
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
				printf("Enter item to count occurance:");
				scanf("%d",&item);
				countOcc(item);
			  break;
			case 4:
			exit(0);
			
		}
	}
}

