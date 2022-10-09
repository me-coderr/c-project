/*Write a program to find all pairs of integers in the linked list whose sum is equal to a given
number.
Example:
Given number=7
LL: 3 2 8 1 6 4 11
This will return (3,4) and (6,1)*/

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
        newnode->next=NULL;
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
    }
    printf("\n");
}

void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void sumpairs(int n)
{
    struct node *moving, *temp;
    int c;
    for(int i=1;i<n;i++)
    {
        c=i;
        temp=head;
        while(--c!=0)
        {
            temp=temp->next;
        }
        moving=temp->next;
        for(int j=i+1;j<n;j++)
        {
            if((temp->data+moving->data)==n)
            {
                printf("(%d,%d)\t",temp->data,moving->data);
            }
            moving=moving->next;
        }
    }
}

int main()
{
    int n, num;
    printf("\ncreate a list first:\n");
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    printf("\nthe list you entered:\n");
    display();
    printf("\nenter the number whose sum pairs are required:\n");
    scanf("%d",&num);
    printf("\nthe sumpairs are:\n");
    sumpairs(num);
    return 0;
}