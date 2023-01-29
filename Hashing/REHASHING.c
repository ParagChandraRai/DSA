#include<stdio.h>
#include<stdlib.h>
int n=5;
int ht[5];
void display()
{
    int i;
    for(i = 0; i < n; i++)
        printf("ht[%d] = %d\n",i,ht[i]);
}
void resize()
{
	int a[n];
	int i;
	
	for(i=0;i<n;i++)
	    a[i]=ht[i];
	n=n*2;
	for(i=0;i<n;i++)
	    ht[i]=-1;
	    
	for(i=0;i<n/2;i++)
	  ht[i]=a[i];
	  
}
void insert()
{   
    int static count=0;
    count++;
    if(n-2==count)//loading factor  can be approx 75%
       resize();
     
    
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
      display();
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
/*
1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:11
ht[0] = -1
ht[1] = 11
ht[2] = -1
ht[3] = -1
ht[4] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:22
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = -1
ht[4] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:66
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = -1
ht[4] = -1
ht[5] = -1
ht[6] = 66
ht[7] = -1
ht[8] = -1
ht[9] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:77
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = -1
ht[4] = -1
ht[5] = -1
ht[6] = 66
ht[7] = 77
ht[8] = -1
ht[9] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:88
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = -1
ht[4] = -1
ht[5] = -1
ht[6] = 66
ht[7] = 77
ht[8] = 88
ht[9] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:33
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = 33
ht[4] = -1
ht[5] = -1
ht[6] = 66
ht[7] = 77
ht[8] = 88
ht[9] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:99
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = 33
ht[4] = -1
ht[5] = -1
ht[6] = 66
ht[7] = 77
ht[8] = 88
ht[9] = 99

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:22
Collision Occurs:ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = 33
ht[4] = 22
ht[5] = -1
ht[6] = 66
ht[7] = 77
ht[8] = 88
ht[9] = 99
ht[10] = -1
ht[11] = -1
ht[12] = -1
ht[13] = -1
ht[14] = -1
ht[15] = -1
ht[16] = -1
ht[17] = -1
ht[18] = -1
ht[19] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.1
Enter the value:55
ht[0] = -1
ht[1] = 11
ht[2] = 22
ht[3] = 33
ht[4] = 22
ht[5] = -1
ht[6] = 66
ht[7] = 77
ht[8] = 88
ht[9] = 99
ht[10] = -1
ht[11] = -1
ht[12] = -1
ht[13] = -1
ht[14] = -1
ht[15] = 55
ht[16] = -1
ht[17] = -1
ht[18] = -1
ht[19] = -1

 1.Insert
 2.Display
 3.Exit
 Enter your option.*/
