#include<stdio.h>
int cal(int x,int y)
{
	if(x<y)
	 return 0;
	 return cal(x-y,y)+1;
	 
}
int main()
{
	int a,b;
	printf("Enter First number:");
	scanf("%d",&a);
	printf("Enter second number:");
	scanf("%d",&b);
	
	printf("Result:%d",cal(a,b));
	return 0;
}
/*Enter First number:100
Enter second number:20
Result:5*/
