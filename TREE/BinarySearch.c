#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *insert(struct node *ptr,int key)
{
	if(ptr==NULL)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->info=key;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
		
	}
	else if(key < ptr->info)
	{
		ptr->lchild=insert(ptr->lchild,key);
	}
	else if(key > ptr->info)
	{
		ptr->rchild=insert(ptr->rchild,key);
	}
	else 
	printf("\nDuplicate key:");
	
	return ptr; 
}
void inorder(struct node *ptr)
{
	
	if(ptr==NULL)
	{
		 return;
	}
	 
	inorder(ptr->lchild);
	printf("%d ",ptr->info);
	inorder(ptr->rchild);
}
void preorder(struct node *ptr)
{
	
	if(ptr==NULL)
	{
		 return;
	}
	printf("%d ",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}
void postorder(struct node *ptr)
{
	
	if(ptr==NULL)
	{
		 return;
	}
	 
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d ",ptr->info);
} 
struct node *Rsearch(struct node *ptr,int key)
{
	if(ptr==NULL)
	{
		return NULL;
	}
	else if(key <ptr->info)
	  return Rsearch(ptr->lchild,key);
	else if( key > ptr->info)
	  return Rsearch(ptr->rchild,key);
	return ptr;
}
struct node *Min(struct node *ptr)
{
	if(ptr!=NULL)
	 while(ptr->lchild!=NULL)
	   ptr=ptr->lchild;
	   
	return ptr;
}
struct node *Max(struct node *ptr)
{
	if(ptr!=NULL)
	 while(ptr->rchild!=NULL)
	   ptr=ptr->rchild;
	   
	return ptr;
}
int height(struct node *ptr)
{
	int x=0,y=0;
	if(ptr==NULL)
	  return 0;
	x=height(ptr->lchild);
	y=height(ptr->rchild);
	if(x>y)
	 return x+1;
	return y+1;
}
int count(struct node *ptr)
{
	int x,y;
	if(ptr!=NULL)
	{
		x=count(ptr->lchild);
		y=count(ptr->rchild);
		return x+y+1;
	}
	return 0;
}
//Count External Node
int Ecount(struct node *ptr)
{
	if(ptr==NULL)
      return 0;
   else if((ptr->lchild==NULL) && (ptr->rchild==NULL))
     return 1;
  else
   return (Ecount(ptr->lchild) +Ecount(ptr->rchild));
}

//Count Internal Node
int Icount(struct node *ptr)
{
   if( (ptr==NULL) || ((ptr->lchild==NULL) && (ptr->rchild==NULL)))
    return 0;
  else
  return (Icount(ptr->lchild)+Icount(ptr->rchild) + 1);
}
struct node *del(struct node *ptr,int key)
{
	struct node *temp,*succ;
	if(ptr==NULL)
	{
		printf("Key Not Found:");
		return ;
	}
	if(key<ptr->info)
	 ptr->lchild=del(ptr->lchild,key);
	else if(key > ptr->info)
	  ptr->rchild=del(ptr->rchild,key);
	else
	{
		if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
		{
			succ=ptr->rchild;
			while(succ->lchild)
			  succ=succ->lchild;
			ptr->info=succ->info;
			ptr->rchild=del(ptr->rchild,succ->info);
			
		}
		else
		{
			temp=ptr;
			if(ptr->lchild!=NULL)
			  ptr=ptr->lchild;
			else if(ptr->rchild!=NULL)
			  ptr=ptr->rchild;
			else 
			  ptr=NULL;
			free(temp);
		}
	}
	return ptr;
}
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
int main()
{
	struct node *ptr, *root=NULL;
	int choice,key;
	while(1)
	{
		printf("\n1.INSERT");
		printf("\n2.Search");
		printf("\n3.Inorder");
		printf("\n4.preorder");
		printf("\n5.postorder");
		printf("\n6.Min");
		printf("\n7.Max");
		printf("\n8.Total No of nodes:");
		printf("\n9.Total No of External nodes:");
		printf("\n10.Total No of Internal nodes:");
		printf("\n11.Height:");
		printf("\n12.Mirror image:");
		printf("\n13.Delete:");
		printf("\n14.Print Tree:");

		printf("\n15.EXIT");
		printf("\nEnter your choice::");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Key:");
				scanf("%d",&key);
				root=insert(root,key);
				break;
			case 2:
				printf("Enter the key to search:");
				scanf("%d",&key);
				ptr=Rsearch(root,key);
				if(ptr==NULL)
				  printf("Key not present:");
				else 
				  printf("Key present:");
				break;
			case 3:
				printf("\n Inorder traversal:");
				inorder(root);
			    break;
			case 4:
			    printf("\n preorder traversal:");
				preorder(root);
				break;
			case 5:
				printf("\n Postorder traversal:");
				postorder(root);
				break;
		    case 6:
		    	ptr=Min(root);
		    	if(ptr!=NULL)
		    	  printf("\nMin:%d ",ptr->info);
		    	break;
		    case 7:
		    	ptr=Max(root);
		    	if(ptr!=NULL)
		    	  printf("\nMax:%d ",ptr->info);
		    	break;
		    case 8:
		    	printf("Total Node:%d",count(root));
		    	break;
		    case 9:
		    	printf("Total External Node:%d",Ecount(root));
		    	break;
		    case 10:
		    	printf("Total Internal Node:%d",Icount(root));
		    	break;
		    case 11:
		    	printf("Height of Tree:%d",height(root));
		    	break;
		    case 12:
		    	//root=mirrorImage(root);
		    	break;
		    case 13:
		    	printf("Enter the key to be Deleted:");
		    	scanf("%d",&key);
		    	root=del(root,key);
		    	break;
		    case 14:
		    	print2D(root);
		    	break;
			case 15:
				exit(0);
		}
	}
	
}
