#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define COUNT 10
struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
	int balance;
};
struct node *insert_LeftBalance(struct node *pptr);
struct node *RotateRight(struct node *pptr);
struct node *insert_RightBalance(struct node *pptr);
struct node *RotateLeft(struct node *pptr);
struct node *insert_right_check(struct node *pptr,int *ptaller);
void print2DUtil(struct node* root, int space)
{
	int i;
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->rchild, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);
    print2DUtil(root->lchild, space);
}
void print2D(struct node* root)
{
    print2DUtil(root, 0);
}
struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr,*bptr;
	aptr=pptr->rchild;
	if(aptr->balance==-1)
	{
		pptr->balance=0;
		aptr->balance=0;
		pptr=RotateLeft(pptr);
	}
	else
	{
		bptr=aptr->lchild;
		switch(bptr->balance)
		{
			case -1:
				pptr->balance=1;
				aptr->balance=0;
				break;
			case 1:
				pptr->balance=0;
				aptr->balance=-1;
				break;	
			case 0:
				pptr->balance=0;
				aptr->balance=0;
				break;
		}
		bptr->balance=0;
		pptr->rchild=RotateRight(aptr);
		pptr=RotateLeft(pptr);
	}
	return pptr;
}

struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr,*bptr;
	aptr=pptr->lchild;
	if(aptr->balance==1)
	{
		pptr->balance=0;
		aptr->balance=0;
		pptr=RotateRight(pptr);
	}
	else
	{
		bptr=aptr->rchild;
		switch(bptr->balance)
		{
			case -1:
				pptr->balance=0;
				aptr->balance=1;
				break;
			case 1:
				pptr->balance=-1;
				aptr->balance=0;
				break;	
			case 0:
				pptr->balance=0;
				aptr->balance=0;
				break;
		}
		bptr->balance=0;
		pptr->lchild=RotateLeft(aptr);
		pptr=RotateRight(pptr);
	}
	return pptr;
}

struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	aptr=pptr->rchild;
	pptr->rchild=aptr->lchild;
	aptr->lchild=pptr;
	return aptr;
}
struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr=pptr->lchild;
	pptr->lchild=aptr->rchild;
	aptr->rchild=pptr;
	return aptr;
}

struct node *insert_right_check(struct node *pptr,int *ptaller)
{
	switch(pptr->balance)
	{
		case 0:
		    pptr->balance=-1;
	    	break;
		case 1:
			pptr->balance=0;
			*ptaller=FALSE;
			break;
		case -1:
			pptr=insert_RightBalance(pptr);
			*ptaller=FALSE;
	}
	return pptr;
}

struct node *insert_left_check(struct node *pptr,int *ptaller)
{
	switch(pptr->balance)
	{
		case 0:
		pptr->balance=1;
		break;
		case -1:
			pptr->balance=0;
			*ptaller=FALSE;
			break;
		case 1:
			pptr=insert_LeftBalance(pptr);
			*ptaller=FALSE;
	}
	return pptr;
}
struct node *insert(struct node *pptr,int key)
{
	static int taller;
	if(pptr==NULL)
	{
		pptr=(struct node*)malloc(sizeof(struct node));
		pptr->lchild=NULL;
		pptr->rchild=NULL;
		pptr->info=key;
		pptr->balance=0;
		taller=TRUE;
	}
	else if(key<pptr->info)
	 {
	 	pptr->lchild=insert(pptr->lchild,key);
	 	if(taller==TRUE)
	 	  pptr=insert_left_check(pptr,&taller);
	 }
	 else if(key>pptr->info)
	 {
	 	pptr->rchild=insert(pptr->rchild,key);
	 	if(taller==TRUE)
	 	  pptr=insert_right_check(pptr,&taller);
	 }
	 else
	 {
	 	printf("Duplicate value.");
	 	taller=FALSE;
	 }
	 return pptr;
}
void inorder(struct node *ptr)
{
	if(ptr==NULL)
	 return;
	inorder(ptr->lchild);
	printf("%d ",ptr->info);
	inorder(ptr->rchild);
}
///Right
int main()
{
	int choice,key;
	struct node *root=NULL;
	while(1)
	{
		printf("\n1.Insert");
		printf("\n2.Display");
		printf("\n3.print in tree format:");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&key);
				root=insert(root,key);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				print2D(root);
				break;
			case 4:
				exit(0);
		}
	}
}
