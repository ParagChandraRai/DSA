#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start1=NULL,*start2=NULL;
void display(struct node *start);
struct node *create(struct node *start);
void sort();
int main()
{
	struct node *ptr;
	
	printf("Enter the list 1 value\n");
	start1=create(start1);
	printf("Enter the list 2 value\n");
	start2=create(start2);
	printf("List 1 is:\n");
	display(start1);
	printf("List 2 is:\n");
	display(start2);
    ptr=start1;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
	}
	ptr->next=start2;
	sort();
	display(start1);

}
struct node *create(struct node *start)
{
 	struct node *ptr, *new_node;
	int num;
	printf("Enter -1 to End:");
	printf("Enter data:");
	scanf("%d",&num);
	
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
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
		printf("Enter data:");
	    scanf("%d",&num);
	}
	return start;
}
void sort()
{
	struct node *p,*q;
	int temp;
	for(p=start1;p->next!=NULL;p=p->next)
	{
		for(q=p;q!=NULL;q=q->next)
		{
			if(p->data >q->data)
			 {
			 	temp=p->data;
	            p->data=q->data;
	            q->data=temp;
			 }
		}
	}
}
void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void remove()
{
	struct node *p,*q,*temp;
	p=start1;
	while(p->next!=NULL)
	{
		
	}
}
