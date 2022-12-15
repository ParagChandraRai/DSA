// write a program to perform the operation of hashing by using quadratic probing.
#include<stdio.h>
#include<stdlib.h>
#define c1 1 //change c1 & c2 according to question
#define c2 3
#define n 10
int ht[n], i, found = 0, key;

void insert()
{
	int val;
	printf("Enter the value to be Inserted:");
	scanf("%d",&val);
	for(i=0;i<n;i++)
	{
		key=((val%n)+ (c1*i)+(c2*i*i)) %n;
		if(ht[key]==-1)
		{
			ht[key]=val;
			break;
		}
	}
}
void display() 
{
  for (i = 0; i < n; i++)
    printf("\t%d", ht[i]);
}
void search()
{
	int val;
	int flag=0;
	printf("Enter the value  to be Searched:");
	scanf("%d",&val);
	for(i=0;i<n;i++)
	{
		key=((val%n)+ (c1*i)+(c2*i)) %n;
		if(ht[key]==val)
		{
			flag=1;
			printf("Value find at index %d:",key);
			break;
		}
	}
	if(flag==0)
	 printf("value is not found:");
}
int main() {
  int option;

  for (i = 0; i < 10; i++) //to initialize every element as ‘–1’
    ht[i] = -1;
  do {
    printf("\n MENU \n1.Insert \n2.Search \n3.Display \n4.Exit");
    printf("\n Enter your option.");
    scanf("%d", & option);
    switch (option) {
    case 1:
      insert();
      break;
    case 2:
      search();
      break;
    case 3:
      display();
      break;
    default:
      printf("\nInvalid choice entry!!!\n");
      break;
    }
  } while (option != 4);

  getch();
  return 0;
}

