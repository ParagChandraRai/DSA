#include<stdio.h>
#include<stdlib.h>
int i,key;
#define n 10
int ht[n];
void insert()
{
	int val;
	int flag=1;
	printf("Enter the value");
	scanf("%d",&val);
	key=val%10;
	if(ht[key]==-1)
	 ht[key]=val;
	else
	{
	   for(i=key+1;i<n;i++)
       {
    	if(ht[i]==-1)
    	{
    		flag=0;
    		ht[i]=val;
    		break;
		}
		printf("Collision occurs:");
	   }
	   if(flag==1)
	    {
		for(i=0;i<key;i++)
		{
			if(ht[i]==-1)
    	    {
    		ht[i]=val;
    		break;
		    }
		  printf("Collision occurs:");
		}
	   }	
	}
}
void search()
{
	int val;
	int flag=0;
	printf("Enter the value to search");
	scanf("%d",&val);
	key=val%10;
	if(ht[key]==val)
	   printf("Key found:");
	else
	{
	   for(i=key+1;i<n;i++)
       {
    	if(ht[i]==val)
    	{
    		flag=1;
    		printf("Key found:");
    		break;
		}

	   }	
	}
	if(flag==0)
	{
		for(i=0;i<key;i++)
		{
			if(ht[i]==val)
    	    {
    		  printf("Key not found:");
    	    	break;
		    }
		}
	}
}
void del()
{
	int val;
	int flag=0;
	printf("Enter the value to deleted");
	scanf("%d",&val);
	key=val%10;
	if(ht[key]==val)
	 ht[key]=-1;
	else
	{
	   for(i=key+1;i<n;i++)
       {
    	if(ht[i]==val)
    	{
    		flag=1;
    		ht[i]=-1;
    		break;
		}
		printf("Collision occurs:");
	   }	
	}
	if(flag==0)
	{
		for(i=0;i<key;i++)
		{
			if(ht[i]==val)
    	    {
    		ht[i]=-1;
    		break;
		    }
		}
	}
}
void display()
{
	for(i=0;i<n;i++)
	  printf("%d  ",ht[i]);
}
int main()
{
int i;
    for(i=0;i<n;i++)
      ht[i]=-1;
	int choice;
	while(1)
	{
		printf("\n1.Insert:");
		printf("\n2.Display:");
		printf("\n3Search:");
		printf("\n4.Delete:");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				 del();
				 break;
				 
		}
		
	}
}
