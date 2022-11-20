/*
	Name: PARAG CHANDRA RAI
	Copyright: 
	Author: 
	Date: 20-11-22 10:50
	Description: Reverse a list of of given numbers.
*/
#include<stdio.h>
int stack[10];
int top=-1;
void push(int n);
int pop();
int main()
{
	int n,val,i,a[10];
	printf("Enter the number of Element:");
	scanf("%d",&n);
	printf("\nEnter the element of arrray:");
	for(i=0;i<n;i++)
	 scanf("%d",&a[i]);
	 
	for(i=0;i<n;i++)
	 push(a[i]);
	 
	for(i=0;i<n;i++)
	{
		val=pop();
		a[i]=val;
	}
	printf("\n Reversed array is:\n");
	for(i=0;i<n;i++)
	 printf("%d ",a[i]);
	
}
void push(int item)
{
	top++;
	stack[top]=item;
}

int pop()
{
	return (stack[top--]);
}
