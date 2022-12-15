#include<stdio.h>
#include<stdlib.h>
# define n 10
int ht[n];

void display()
{
    int i;
    for(i = 0; i < n; i++)
        printf("ht[%d] = %d\n",i,ht[i]);
}
void del()
{
	int value;
	printf("Enter the value to be deleted:");
	scanf("%d",&value);
    int key = value % n;
    if(ht[key] == value)
        ht[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}
void search()
{
	int value;
	printf("Enter the value to be searched:");
	scanf("%d",&value);
    int key = value % n;
    if(ht[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}
void insert()
{   
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    int key = value % n;
    
    if(ht[key] == -1)
    {   
        ht[key] = value;
        printf("%d inserted at ht[%d]\n", value,key);
    }
    else
    {   
        printf("Collison occurs");
    }
}
int main() {
  int i, option;
   
  for (i = 0; i < n; i++) //to initialize every element as ‘–1’
    ht[i] = -1;
  do {
    printf("\n MENU \n1.Insert \n2.Search \n3.Display \n4.Delete\n5.Exit");
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
    case 4:
    	del();
        break;
    default:
      printf("\nInvalid choice entry!!!\n");
      break;
    }
  } while (option != 5);
  return 0;
}

