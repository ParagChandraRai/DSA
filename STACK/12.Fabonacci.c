//
/*
	Name: PARAG CHANDRA RAI
	Copyright: 
	Author: 
	Date: 20-11-22 10:50
	Description: fabonacci series using recursion
*/
#include<stdio.h>
int fab(int n)
{
	if(n==0)
	  return 0;
	else if(n==1)
	  return 1;
	return fab(n-1)+fab(n-2);
}
int  main()
{
	int n,i;
	printf("enter number of terms");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  printf("%d ",fab(i));
	  return 0;
}
