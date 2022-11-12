//23.write a program to form a linked list of floating point numbers .Display the sum and mean.
#include<stdio.h>
#include<stdlib.h>
struct node{
	float data;
	struct node *next;
}*start=NULL;
void create()
{
	struct node *ptr,*new_node;
	float num;
	printf("Enter -1 to End:");
	printf("Enter floating pont data:");
	scanf("%f",&num);
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
		printf("Enter floating pont data:");
	    scanf("%f",&num);
	}
	
}

void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%.2f ",ptr->data);
		ptr=ptr->next;
	}
}
void summean()
{
	float sum;
	int count=0;
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		sum=sum+ptr->data;
		ptr=ptr->next;
		count++;
	}
	printf("Sum :%.2f",sum);
	printf("\nMean:%.2f",sum/count);
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Create");
		printf("\n2.Dispaly");
		printf("\n.3.Sum and Mean");
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
				summean();
			  break;
			case 4:
			exit(0);
			
		}
	}
}
