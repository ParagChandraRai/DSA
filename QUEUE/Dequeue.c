#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;
int stack[20];
int top=-1;
void insert_Rear(int item)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
 
  temp->info=item;
  temp->link=NULL;
  
  if(front==NULL)
    front=temp;
  else
    rear->link=temp;
    
    rear=temp;
	
}
void insert_Front(int item)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
 
  temp->info=item;
  temp->link=NULL;
  
  if(rear==NULL)
    rear=temp;
  else
    temp->link=front;
    
    front=temp; 
	
}
int del_Front()
{
	struct node *temp;
	int item;
	temp=front;
	item=temp->info;
	front=front->link;
	free(temp);
	return item;
}
int del_Rear()
{
	struct node *pre,*ptr,*temp;
	int item;
	if(front==rear)
    {
    	item=front->info;
        free(front);
        front=NULL;
        rear=NULL;
        return item;
    }
	ptr=front;
	while(ptr->link!=rear)
	{
		ptr=ptr->link;
	}
	item=rear->info;
	temp=rear;
    rear=ptr;
    ptr->link=NULL;
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
        printf("\n 1. INSERT AT FRONT END");
        printf("\n 2. INSERT AT REAR END");
        printf("\n 3. DELETE FROM REAR END");
        printf("\n 4. DELETE FROM FRONT END");
		printf("\n 5. DISPLAY");
		printf("\n 6. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("Enter the element for insertion:");
				scanf("%d",&item);
				insert_Front(item);
				break;
			case 2:
				printf("Enter the element for insertion:");
				scanf("%d",&item);
				insert_Rear(item);
				break;
			case 3:
				printf("Deleted Item at the REAR of queue %d",del_Rear());
				break;
			case 4:
				printf("Deleted Item at the REAR of queue %d",del_Front());
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
		}
	}
}
