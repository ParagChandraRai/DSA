#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *start = NULL;
struct node *start1 = NULL;

struct node *insert_end(struct node *start,int num)
{
	struct node *ptr, *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = NULL;
	if(start==NULL)
	{
		start=new_node;
		return start;
	}
	ptr = start;
	
	while(ptr -> next != NULL)
	  ptr = ptr -> next;
	
	ptr -> next = new_node;
return start;
}

void display(struct node *start)
{
	struct node *ptr;
	ptr = start;
    while(ptr != NULL)
    {
	 printf("\t %d", ptr -> data);
	 ptr = ptr -> next;
   }

}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int i;
	for(i=0;i<6;i++)
	  start=insert_end(start,arr[i]);
	printf("List is\n");
	
	display(start);
	
	for(i=0;i<6;i=i+2)
	{
		start1=insert_end(start1,arr[i]);
	}
	  
	printf("\n\nNew Linked List is:\n");
	  display(start1);
	
}
