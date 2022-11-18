#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
 int data;
 struct node *next;
}*start=NULL;
struct node *start1=NULL;
struct node *create_cll(struct node *start)
{
	 struct node *new_node, *ptr;
	int num;
	printf("\n Enter –1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num!=-1)
	{
	 new_node = (struct node*)malloc(sizeof(struct node));
	 new_node -> data = num;
	 if(start == NULL)
	 {
	 new_node -> next = new_node;
	  start = new_node;
	 }
	 else
	 { 
		 ptr = start;
		 while(ptr -> next != start)
		 ptr = ptr -> next;
		 ptr -> next = new_node;
		 new_node -> next = start;
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
	while(ptr -> next != start)
	{
	  printf("\t %d", ptr -> data);
	  ptr = ptr -> next;
	}
	printf("\t %d", ptr -> data);
	return start;
}
int main()
{
	start=create_cll(start);
	display(start);
	start1=start;
	printf("\nAfter coping..\n");
	display(start1);
}
