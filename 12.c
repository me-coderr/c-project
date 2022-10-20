/*Given two lists sorted in increasing order, create and return a new list representing the intersection
of the two lists. The new list should be made with its own memory — the original lists should not be
changed.
Input: List1: 3,5,7,9,10,11,12,21 and List2: 2,5,8,10,13,17,20,21,33
Output: List 5,10,21 If no common element it will show that msg.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *headNew=NULL, *head1=NULL, *head2=NULL;

struct node* create(int n, struct node *head)
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
    return head;
}

void display(struct node *head)
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

void intersect(int n1, int n2)
{
    struct node *temp1=head1, *temp2=head2, *temp=headNew, *newnode=NULL;
    for(int i=1;i<=n1;i++)
    {
        temp2=head2;
        for(int j=1;j<=n2;j++)
        {
            if(temp1->data==temp2->data)
            {
                temp=headNew;
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=temp1->data;
                newnode->next=NULL;
                if(headNew==NULL)
                {
                    headNew=newnode;
                }
                else
                {
                    temp=headNew;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

int main()
{
    int n1, n2;
    printf("\nenter the number of node in list 1:\n");
    scanf("%d",&n1);
    head1=create(n1, head1);
    printf("\ntime for list 2\n\nnumber of nodes in list 2\n");
    scanf("%d",&n2);
    head2=create(n2, head2);
    printf("\nthe lists you entered:\n1: ");
    display(head1);
    printf("2: ");
    display(head2);
    intersect(n1, n2);
    if(headNew==NULL)
    {
        printf("\nthe 2 lists do not intersect at any node\n");
    }
    else
    {
        printf("\nintersection of the 2 lists you entered :\n");
        display(headNew);
    }
    printf("\n");
    return 0;
}