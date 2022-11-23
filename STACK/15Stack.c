#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char info[1000];  
    struct node *next; 
} node;
void push(node **t, char data[])
{
	int i;
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Not enough memory\n");
    }
    else
    {
        for (i = 0; i < data[i] != '\0'; i++)
            temp->info[i] = data[i];
        temp->info[strlen(data)] = '\0';
        if (*t == NULL)
        {
            *t = temp;
            temp->next = NULL;
        }
        else
        {
            temp->next = *t;
            *t = temp;
        }
    }
}
void pop(node **t)
{

    printf("Name popped %s\n", (*t)->info);
    node *temp = *t;
    *t = (*t)->next;
    free(temp);
}
void display(node *t)
{
    if (t == NULL)
        printf("Stack is empty\n");
    else
    {
        while (t != NULL)
        {
            printf("%s\n", t->info);
            t = t->next;
        }
    }
}

void main()
{
    int n;
    char ch;
    int choice;
    char name[100];
    node *top = NULL;
    do
    {

        printf("Press 1 to store name into the stack. press 2 to pop the topmost name in stack\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter name of student to be stored in stack\n");
            fflush(stdin);
            scanf("%s", &name);
            push(&top, name);
        }
        else if (choice == 2)
        {
            if (top != NULL)
                pop(&top);
            else 
                printf("Stack is empty\n");
        }
        else
            printf("Wrong choice\n");

        printf("Do you want to continue?\n");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    printf("\nNames stored in stack are:\n");
    display(top);
}
