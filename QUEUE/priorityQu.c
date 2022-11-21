#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	int priority;
	struct node *link;
}*front=NULL,*rear=NULL;
void insert(int item,int pr)
{
  struct node *ptr,*temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  {
  	printf("Memory is not available:");
  	return;
  }
  temp->info=item;
  temp->priority=pr;
  temp->link=NULL;
  if(isEmpty()|| pr< front->priority)
  {
  	temp->link=front;
  	front=temp;
  }
  else
  {
  	ptr=front;
  	while(ptr->link!=NULL && ptr->link->priority <= pr)
  	  ptr=ptr->link;
  	  
  	  temp->link=ptr->link;
  	  ptr->link=temp;
  }
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
	   printf(" %d[priority=%d]", ptr->info, ptr->priority );	
		ptr=ptr->link;
	}
}
int main()
{
	int option,item,pr;
	while(1)
	{
		printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("Enter the element for insertion:");
				scanf("%d",&item);
				printf("Enter its priority:");
				scanf("%d",&pr);
				insert(item,pr);
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
				exit(0);
		}
	}
}
