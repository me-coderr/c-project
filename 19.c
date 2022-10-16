/*Write a program to remove duplicate nodes from a linked list.
Example:
LL: 3 4 2 3 6 3 4 5 2 2
Output: 3 4 2 6 5*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
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

void removeDuplicates(int n)
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
        moving=temp;
        for(int j=i+1;j<=n;j++)
        {
            if(temp->data==(moving->next)->data)
            {
                moving->next=(moving->next)->next;
                --n;
            }
            moving=moving->next;
        }
    }
}

int main()
{
    int n;
    printf("\ncreate a list first:\n");
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    printf("\nthe list you entered:\n");
    display();
    removeDuplicates(n);
    printf("\nthe list after removing all the duplicates:\n");
    display();
    return 0;
}