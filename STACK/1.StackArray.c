/*
	Name: PARAG CHANDRA RAI
	Copyright: 
	Author: 
	Date: 20-11-22 10:50
	Description: STACK USING ARRAY
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int);
int pop();
int peek();
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
		printf("\nEnter your choice");
		scanf("%d",&choice);
		system("cls");
		switch(choice)
		{
			case 1:
			   printf("Enter the item");
			   scanf("%d",&item);
			   push(item);
			break;
			case 2:
				item=pop();
				printf("Popped Item is %d",item);
			    break;
			case 3:
				item=peek();
				printf("Item at the top is:%d",item);
			break;
			case 4:
				display();
			break;
		    case 5:
		    	exit(1);
		}
	}
}
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Stack is Overflow:");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("Stack is underflow");
	}
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}
int peek()
{
	if(top==-1)
	{
		printf("Stack is Empty");
	}
	return stack[top];
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is Empty");
	}
	else
	{
	
	   printf("Stack element is:");
    	for(i=top;i>=0;i--)
    	printf("%d ",stack[i]);
   }
}

