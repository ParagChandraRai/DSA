/*
	Name: PARAG CHANDRA RAI
	Copyright: 
	Author: 
	Date: 20-11-22 10:48
	Description: STACK USING LINKED LIST
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*top=NULL;
void push(int item);
int pop();
int isEmpty();
void display();
int main()
{
	
	int choice,item;
	while(1)
	{
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.PEEK");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		system("cls");
		switch(choice)
		{
			case 1:
			 printf("Enter the element to Insert:");
			 scanf("%d",&item);
			 push(item);
			break;
			case 2:
				printf("Popped Item is: %d",pop());
			break;
			case 3:
				printf("Item at the top of stack is:%d",peek());
			break;
			case 4:
				display();
			break;
			case 5:
			exit(0);
		}
	}
}
void push(int item)
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=item;
	new_node->next=top;
	top=new_node;
	
}
int pop()
{
	int item;
	struct node *temp;
	if(isEmpty())
	{
		printf("stack is underflow");
	}
	else
	{
		temp=top;
		item=top->data;
		top=top->next;
		free(temp);
		return item;
	}
}
int peek()
{
	if(isEmpty())
	{
		printf("stack is underflow");
	}
	else
	return top->data;
}
void display()
{
	struct node *ptr;
	ptr=top;
	if(isEmpty())
	{
		printf("stack is empty");
	}
	else
	{
		printf("Stack Element is:\n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
			
		}
	}
}
int isEmpty()
{
	if(top==NULL)
	  return 1;
	else
	 return 0;
}

