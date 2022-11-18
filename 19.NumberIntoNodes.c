//19..write a program to input n digit number breaks  into individual nodes. 

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL;
void insertAtBeg(int num)
{
	//printf("*");
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	

}
void display()
{
	printf("Linked List is:\n");
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int num,rem=0;
	printf("Enter the number to break into individual node:\n");
	scanf("%d",&num);
	while(num!=0)
	{
	  rem=num%10;
      insertAtBeg(rem);
      num=num/10;
	}
	display();
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms

