#include <stdio.h>
void qsort();
int n;
void main()
{
	int a[100],i,l,r;
	printf("\nENTER THE SIZE OF THE ARRAY: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nENTER NUMBER-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nTHE ARRAY ELEMENTS BEFORE SORTING: \n");
	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
	l=0;
	r=n-1;
	qsort(a,l,r);
	printf("\nTHE ARRAY ELEMENTS AFTER SORTING: \n");
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
}
void qsort(int b[],int left,int right)
{
	int i,j,p,tmp,finished,k;
	if(right>left)
	{
		i=left;
		j=right;
		p=b[left];
		finished=0;
		while (!finished)
		{
			do
			{
				++i;
			}
			while ((b[i]<=p) && (i<=right));
			while ((b[j]>=p) && (j>left))
			{
				--j;
			}
			if(j<i)
				finished=1;
			else
			{
				tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
			}
		}
		tmp=b[left];
		b[left]=b[j];
		b[j]=tmp;
		qsort(b,left,j-1);
		qsort(b,i,right);
	}
	return;
}
