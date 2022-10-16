/*Reverse the list of elements in a circular linked list.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head=NULL;
struct node *head_rev=NULL;

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
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        newnode->next=head;
    }
    printf("\n");
}

void display(struct node *headDisplay)
{
    struct node *temp=headDisplay;
    while(temp->next!=headDisplay)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\t::\t%d",temp->data,(temp->next)->data);
    printf("\n");
}

void reverse(int n)
{
    struct node *temp_rev, *temp;
    int c=n;
    while(c--!=0)
    {
        temp=head;
        for(int i=1;i<=c;i++)
        {
            temp=temp->next;
        }
        if(head_rev==NULL)
        {
            head_rev=temp;
            temp_rev=head_rev;
        }
        else
        {
            temp_rev->next=temp;
            temp_rev=temp_rev->next;
        }
    }
    temp_rev->next=head_rev;
    temp_rev=temp_rev->next;
}

int main()
{
    int n;
    printf("\ncreate a circular list first:\n");
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    printf("\nthe circular list you entered:\n");
    display(head);
    reverse(n);
    printf("\nthe circular list after being reversed:\n");
    display(head_rev);
    return 0;
}