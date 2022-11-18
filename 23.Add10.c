#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *next; 
  int data;
 struct node *prev;
};
void add10();
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *create_ll(struct node *start);
int main()
{
	start = create_ll(start);
    start=display(start);
    add10();
    printf("\nAfter adding 10..\n");
     start=display(start);
}
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter –1 to end");
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
void add10()
{
	struct node *ptr;
	ptr=start;
  while(ptr!=NULL)
   {
	  ptr -> data=ptr->data +10;
	 ptr = ptr -> next;
   }
}
