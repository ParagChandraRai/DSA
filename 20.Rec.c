#include<stdio.h>
int fun(int x,int y)
{
	if(x==0 ||x>=y>=1)
	  return 1;
	 return fun(x-1,y)+fun(x-1,y-1);
	 
}
int main()
{
	int a,b;
	printf("Enter First number:");
	scanf("%d",&a);
	printf("Enter second number:");
	scanf("%d",&b);
	
	printf("Result:%d",fun(a,b));
	return 0;
}
/*Enter First number:5
Enter second number:50
Result:32*/
