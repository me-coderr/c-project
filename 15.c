/*Write a program that prints the minimum and maximum element of a single linked list traversing the
list only once.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head=NULL;

void create(int n)
{
    struct node *temp, *newnode;
    for(int i=1;i<=n;i++)
    {
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nenter data for node %d\n",i);
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        newnode->next=NULL;
    }
    printf("\n");
}

void display()
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

void maxmin()
{
    int max=-999999999, min=999999999;
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data>max)
        {
            max=temp->data;
        }
        if(temp->data<min)
        {
            min=temp->data;
        }
        temp=temp->next;
    }
    printf("\nmax number present in the list:\t%d\nmin number present in the list:\t%d\n\n",max,min);
}

int main()
{
    int n;
    printf("\ncreate a linked list first:\n");
    printf("\nenter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    printf("\nthe list you entered:\n");
    display(head);
    maxmin();
    return 0;
}