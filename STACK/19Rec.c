#include<stdio.h>
int Lam(int n)
{
	
     if(n==0)
       return 1;
	 return Lam(n/2)+1;
	 
}
int main()
{
	int a,b;
	printf("Enter  number:");
	scanf("%d",&a);

	
	printf("Result:%d",Lam(a));
	return 0;
}
/*Enter  number:5
Result:4*/
