#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;
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
void count()
{
	struct node *ptr;
	ptr=front;
	int count=0;
		if(isEmpty())
	{
		printf("Queue is Empty:");
		return;
	}
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("NO of element in the Queue %d",count);
}
int main()
{
	int option,item;
	while(1)
	{
		printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. Display");
        printf("\n 3.Count");
		printf("\n 4. EXIT");
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
	            display();
	         break;
			case 3:
			    count();
				break;
			case 4:
				exit(0);
		}
	}
}
