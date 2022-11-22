#include<stdio.h>
int GCD(int a ,int b)
{
	if(b==0)
	  return a;
	return GCD(b,a%b);
	
}
int main()
{
	int a,b;
	printf("Enter two number:");
	scanf("%d%d",&a,&b);
	printf("GCD:%d",GCD(a,b));
}
