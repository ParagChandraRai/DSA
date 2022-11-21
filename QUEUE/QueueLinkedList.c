#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;

int stack[20];
int top=-1;
void push(int item)
{
	stack[++top]=item;
}
int pop()
{
	return (stack[top--]);
}
void insert(int item)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  {
  	printf("Memory is not available:");
  	return;
  }
  temp->info=item;
  temp->link=NULL;
  if(front==NULL)
    front=temp;
  else
    rear->link=temp;
    
    rear=temp;
	
}
int del()
{
	struct node *temp;
	int item;
	if(isEmpty())
	{
		printf("Queue is Empty:");
		return;
	}
	temp=front;
	item=temp->info;
	front=front->link;
	free(temp);
	return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("Queue is Empty:");
		return;
	}
	return front->info;
}
int isEmpty()
{
	if(front==NULL)
	  return 1;
	else
	  return 0;
}
 void rev()
 {
 	struct node *ptr;
 	ptr=front;
 	while(ptr!=NULL)
 	{
 	  push(ptr->info);
 	  ptr=ptr->link;
    }
 	  
 	ptr=front;
 	while(ptr!=NULL)
 	{
 		int item=pop();
 	  ptr->info=item;
	  ptr=ptr->link;	
	}
 }
void display()
{
	struct node *ptr;
	ptr=front;
		if(isEmpty())
	{
		printf("Queue is Empty:");
		return;
	}
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
}
int main()
{
	int option,item;
	while(1)
	{
		printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5.Reverse:");
		printf("\n 6. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("Enter the element for insertion:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				printf("Deleted element is %d",del());
				break;
			case 3:
				printf("Item at the front of queue %d",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				rev();
				printf("Reverse Successfully..");
				break;
			case 6:
				exit(0);
		}
	}
}
