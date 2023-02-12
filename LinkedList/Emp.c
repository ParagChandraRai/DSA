#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data[20];
	int id;
	struct node *next;
}*start=NULL;
void create()
{
	struct node *newnode,*ptr;
	char a[10];
	int id;
	printf("Enter -1 to End:");
	printf("Enter id:");
	scanf("%d",&id);
	
	printf("Enter Name:");
	scanf("%s",a);
	
	
	while(1)
	{
	    if(id==-1)
	      break;
		newnode=(struct node*)malloc(sizeof(struct node));
		strcpy(newnode->data,a);
	     newnode->id=id;
		newnode->next=NULL;
		
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			  ptr=ptr->next;
			
			ptr->next=newnode;
		}
		printf("Enter id:");
	    scanf("%d",&id);
	    if(id==-1)
	      break;
		printf("Enter name:");
	    scanf("%s",a);
	    
	
	}
}
void display()
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%s",ptr->data);
		printf("%d",ptr->id);
		ptr=ptr->next;
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.create:");
		printf("\n2.Display:");
		printf("\n3.del first");
		printf("\n4.del All");
		printf("\n5.del last");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		}
	}
}
