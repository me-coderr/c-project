/*Given a list, split it into two sublists — one for the front half, and one for the back half. If the number
of elements is odd, the extra element should go in the front list.
Input:-2 4 8 5 6 11 23
Output:- L12 4 8 5 and L26 11 23*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL, *head1=NULL, *head2=NULL;

void create(int n)
{
    struct node *newnode, *temp;
    for(int i=1;i<=n;i++)
    {
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nenter the data for node %d:\n",i);
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

void display(struct node *hD)
{
    struct node *temp=hD;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void split(int n)
{
    head1=head;
    struct node *temp1=head1, *temp2, *temp=head;
    int n1={(n%2==0)?(n/2):(n/2+1)};
    for(int i=1;i<=n;i++)
    {
        if(i<n1)
        {
            temp1->next=temp->next;
            temp1=temp1->next;
            temp=temp->next;
        }
        else if(i==n1)
        {
            temp=temp->next;
            head2=temp;
            temp2=head2;
        }
        else
        {
            temp2->next=temp->next;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    temp1->next=NULL;
}

int main()
{
    int n;
    char c, junk;
    printf("\nenter the number of node:\n");
    scanf("%d",&n);
    create(n);
    printf("\nthe list you entered:\n");
    display(head);
    split(n);
    printf("\nthe splitted lists are :\n\nA :\t");
    display(head1);
    printf("\nB :\t");
    display(head2);
    printf("\n");
    return 0;
}