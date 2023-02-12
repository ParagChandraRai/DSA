#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *creatheader(struct node *start){
	struct node  *new_node,*ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter a number\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		new_node->next=NULL;
		if(start==NULL)
		{
			start=(struct node*)malloc(sizeof(struct node));
			start->next=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			 ptr=ptr->next;
			 
			ptr->next=new_node;
		}
    	printf("Enter a number\n");
	    scanf("%d",&num);
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr=start->next;
	printf("Linked List is:\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
} 
int main()
{
	start=creatheader(start);
	display(start);
}
