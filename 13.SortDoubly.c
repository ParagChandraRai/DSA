#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	struct node *next;
	int data;
	struct node *prev;
}*start=NULL;
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num != -1)
	{
	 if(start == NULL)
	 {
		 new_node = (struct node*)malloc(sizeof(struct node));
		 new_node -> prev = NULL;
		 new_node -> data = num;
		 new_node -> next = NULL;
		 start = new_node; 
	 }
	 else
	 {
		 ptr=start;
		 new_node = (struct node*)malloc(sizeof(struct node));
		 new_node->data=num;
		 while(ptr->next!=NULL)
		 ptr = ptr->next;
		 ptr->next = new_node;
		 new_node->prev=ptr;
		 new_node->next=NULL;
	 }
	 printf("\n Enter the data : ");
	 scanf("%d", &num);
	}
return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
	 printf("\t %d", ptr -> data);
	 ptr = ptr -> next;
	}
	return start;
}

struct node *sort_list(struct node *start)
{
	struct node *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while(ptr1 -> next != NULL)
	{
	   ptr2 = ptr1 -> next;
	    while(ptr2 != NULL)
	    {
	       if(ptr1 -> data > ptr2 -> data)
	        {
				 temp = ptr1 -> data;
				 ptr1 -> data = ptr2 -> data;
				 ptr2 -> data = temp;
	        }
	    ptr2 = ptr2 -> next;
	   }
	 ptr1 = ptr1 -> next;
	}
}
int main()
{
	start=create_ll(start);
	start=display(start);
	*sort_list(start);
	printf("\nAfter sorting..\n");
	start=display(start);
}
