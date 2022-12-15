#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data,key;
	struct node* next;
	
}ps;
ps * temp;
int size,i=0,num,ch,j=0;
void insert(ps ht[],int size)
{
	printf("Enter elemnet");
	scanf("%d",&num);
	temp=ht[num%size].next;
	if(temp==0)
	{
		ps*nn=(ps*)malloc(sizeof(ps));
		nn->data=num;
		nn->next=0;
		ht[num%size].next=nn;
		
	}

else
{
	ps * nn=(ps*)malloc(sizeof(ps));
	nn->data=num;
		nn->next=0;
		while(temp->next!=0)
		{
			temp=temp->next;
			temp->next=nn;
			temp=nn;
		}
}
}
void search(ps ht[],int size)


{
	printf("Enter data");
	scanf("%d",&num);
	if(ht[num%size].next->data==num)
	printf("Eneter at %d ",num%size);
	else if(ht[num%size].next->next!=0)
	{
		ps * ptr =ht[num%size].next->next;
		while(ptr->data!=num)
		
			ptr=ptr->next;
			printf("Exists at %d ",num%size);
			
		
	}
	
}
void main()
{
	int i;
	printf("Enetre size of table");
	scanf("%d",&size);
	ps ntable[size];
	while(i<size)
	{
		ntable[i].next=0;
		i++;
	}
	for(i=0;i<size;i++)
	{
		ntable[i].data=-1;
		ntable[i].key=i;
		
	}
	do
	{
		printf("choose");
		scanf("%d",&ch);
		switch(ch)
		{
		
		case 1:
			insert(ntable,size);
			break;
		case 2:
			search(ntable,size);
			break;
		case 3:
			display(ntable,size);
			break;
	}
	}while(ch!=4);

}
