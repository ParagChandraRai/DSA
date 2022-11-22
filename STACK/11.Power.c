#include<stdio.h>
int powerfun(int a,int b)
{
	if(b==0)
	  return 1;
	return a*powerfun(a,b-1);
}
int main()
{
	int b,e;
	printf("Enter base:");
	scanf("%d",&b);
	printf("Enter Expo:");
	scanf("%d",&e);
	printf("Result:%d",powerfun(b,e));
	return 0;
}
