#include<stdio.h>
#include<stdlib.h>
#define c1 0
#define c2 3
# define n 7
int ht[n];
void display()
{
    int i;
    for(i = 0; i < n; i++)
        printf("ht[%d] = %d\n",i,ht[i]);
}
void insert()
{   
    int value,i;
    printf("Enter the value:");
    scanf("%d",&value);
    int key = value % n;
    if(ht[key]==-1)
       ht[key]=value;
    else
    {
    	for(i=0;i<n;i++)
        {
    	  key=(value%n + i+value%5)%n;
    	  printf("Collision Occurs:");
    	  if(ht[key] == -1)
          {     
           ht[key] = value;
           break;
          }
	    }
	}
}
int main() {
  int i, option;
   
  for (i = 0; i < n; i++)
    ht[i] = -1;
  while(1) 
  {
    printf("\n 1.Insert");
    printf("\n 2.Display");
    printf("\n 3.Exit");
    printf("\n Enter your option.");
    scanf("%d", & option);
    switch (option) {
    case 1:
      insert();
      break;
    case 2:
      display();
      break;
    case 3:
    	exit(0);
    }
  }
  return 0;
}

