/*Write a SortMerge() function that takes two lists, each of which is unsorted. This program will sort
the lists in increasing order, and merges the two together into one list which is also in increasing order.
SortMerge() should return the new list.
Input : List1:9,5,3,10,11 and List2: 20,11,21,5,7
Output: Listres: 3,5,7,9,10,11,20,21
** It omits the duplicate entries.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1=NULL, *head2=NULL;
int n1, n2;

void sort(struct node *head, int n)
{
    struct node *temp=NULL;
    int copy, f;
    for(int i=0;i<n-1;i++)
    {
        f=0;
        temp=head;
        for(int j=0;j<n-i-1;j++)
        {
            if(temp->data > temp->next->data)
            {
                copy=temp->data;
                temp->data=temp->next->data;
                temp->next->data=copy;
                f=1;
            }
            temp=temp->next;
        }
        if(f==0)
            break;
    }
}

struct node* sortMerge(struct node *h1, struct node *h2)
{
    sort(h1, n1);
    sort(h2, n2);
    struct node *temp=h1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=h2;
    temp=temp->next;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    sort(h1, n1+n2);
    return h1;
}

struct node* create(struct node *head, int n)
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
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void removeDuplicates(struct node *head, int n)
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
    printf("\nenter the number of nodes in list 1\n");
    scanf("%d",&n1);
    printf("\ncreate list 1 \n");
    head1=create(head1, n1);
    printf("\ncreate list 2 \n");
    printf("\nenter the number of nodes in list 2\n");
    scanf("%d",&n2);
    head2=create(head2, n2);
    printf("\nthe lists you entered:\n1 :\t");
    display(head1);
    printf("\n2 :\t");
    display(head2);
    removeDuplicates(head1, n1);
    removeDuplicates(head2, n2);
    head1=sortMerge(head1, head2);
    removeDuplicates(head1, (n1+n2));
    printf("\nthe new sorted and merged list :\n");
    display(head1);
    return 0;
}