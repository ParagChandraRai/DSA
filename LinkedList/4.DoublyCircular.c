#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
struct node *next;
int data;
struct node *prev;
};
struct node *start = NULL;
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter �1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num != -1)
	{
	 if(start == NULL)
	 {
		 new_node = (struct node*)malloc(sizeof(struct node));
		 new_node -> prev = NULL;
		 new_node -> data = num;
		 new_node -> next = start;
		 start = new_node;
	 }
	 else
	 {
		 new_node = (struct node*)malloc(sizeof(struct node));
		 new_node -> data = num;
		 ptr = start;
		 while(ptr -> next != start)
		 ptr = ptr -> next;
		 new_node -> prev = ptr;
		 ptr -> next = new_node;
		 new_node -> next = start;
		 start -> prev = new_node;
	 }
	 printf("\n Enter the data : ");
	 scanf("%d", &num);
}
return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start)
	{
	 printf("\t %d", ptr -> data);
	 ptr = ptr -> next;
	}
	printf("\t %d", ptr -> data);
	return start;
}
struct node *insert_beg(struct node *start)
	{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node-> data = num;
	ptr = start;
	while(ptr -> next != start)
	 ptr = ptr -> next;
	
	new_node -> prev = ptr;
	ptr -> next = new_node;
	new_node -> next = start;
	start -> prev = new_node;
	start = new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
	 ptr = ptr -> next;
	
	ptr -> next = new_node;
	new_node -> prev = ptr;
	new_node -> next = start;
	start-> prev = new_node;
return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr,*temp;
	ptr = start;
	while(ptr -> next != start)
	  ptr = ptr -> next;

	ptr -> next = start -> next;
	temp = start;
	start=start->next;
	start->prev=ptr;
	free(temp);
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr -> next != start)
	 ptr = ptr -> next;
	ptr -> prev -> next = start;
	start -> prev = ptr -> prev;
	free(ptr);
	return start;
}


int main()
{
int option;
 do
 {
	 printf("\n\n *****MAIN MENU *****");
	 printf("\n 1: Create a list");
	 printf("\n 2: Display the list");
	 printf("\n 3: Add a node at the beginning");
	 printf("\n 4: Add a node at the end");
	 printf("\n 5: Delete a node from the beginning");
	 printf("\n 6: Delete a node from the end");
	 printf("\n 7: EXIT");
	 printf("\n\n Enter your option : ");
	 scanf("%d", &option);
     switch(option)
    {
		 case 1: start = create_ll(start);
		 printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
		 break;
		 case 2: start = display(start);
		 break;
		 case 3: start = insert_beg(start);
		 break;
		 case 4: start = insert_end(start);
		 break;
		 case 5: start = delete_beg(start);
		 break;
		 case 6: start = delete_end(start);
		 break;
	 }
}while(option != 7);
getch();
return 0;
}
