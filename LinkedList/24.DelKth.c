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

int  getsize()
{
	struct node *ptr;
	ptr=start;
	int size;
	while(ptr!=NULL)
	{
		size++;
		ptr=ptr->next;
	}
	return size;
}

void delkth()
{
	struct node *temp,*ptr,*pre;
	int size=getsize();
	int n;
	printf("Enter the kth node to delete:");
	scanf("%d",&n);
	if(n<1 || n>size)
	 {
	 	printf("Invalid position:");
	 	return;
	 }
	 if(n==1)
	 {
	 	temp=start;
	 	start=start->next;
	 	free(temp);
	 }
	 else
	 {
	   ptr=start;
	   while(--n)
	   {
	 	pre=ptr;
	 	ptr=ptr->next;
	   }
	 pre->next=ptr->next;
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
int main()
{
	int choice,item;
	while(1)
	{
		printf("\n1.Create");
		printf("\n2.Dispaly");
		printf("\n3.Deleted kth Node");
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
				delkth();
				printf("Deleted Successfully...");
			  break;
			case 4:
			exit(0);
			
		}
	}
}
