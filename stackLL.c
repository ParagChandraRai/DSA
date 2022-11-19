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


///linked list
//Stack using Array
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
