/*Write a program to delete the middle element(s) of a linked list by traversing the list only once. If
the list contains odd number of elements, the n/2+1th element will be deleted. On the other hand, if it
contains even number of elements, you need to delete both n/2th and n/2+1 th elements.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

int create()
{
    struct node *newnode;
    struct node *temp;
    int n=0;
    char ch='\0',junk;
    while(ch!='e')
    {
            newnode=(struct node*)malloc(sizeof(struct node));
            temp=head;
            ++n;
            printf("\nenter value of node %d\n",n);
            scanf("%d",&(newnode->data));
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
                temp=temp->next;
            }
            scanf("%c",&junk);
            printf("note : press 'e' if all the nodes are already listed, press enter otherwise.\n");
            scanf("%c",&ch);
    }
    if(ch=='e')
    {
        printf("list creation ended\n");
    }
    return n;
}

void display()
{
    printf("\nlinked list at present :\n");
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("\nNULL\n\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    printf("\n\n");
    }
}

void removeNode(int n)
{
    struct node *temp=head;
    int i=1, r;
    if(n==0)
    {
        printf("\nempty list\n");
    }
    else if(n==1)
    {
        head=NULL;
    }
    else if(n==2)
    {
        head=NULL;
    }
    else if(n%2==1)
    {
        r=n/2+1;
        while((i+1)<r)
        {
            temp=temp->next;
            ++i;
        }
        temp->next=(temp->next)->next;
        temp=temp->next;
        printf("\nnode %d removed\n",r);
    }
    else
    {
        r=n/2;
        while((i+1)<r)
        {
            temp=temp->next;
            ++i;
        }
        temp->next=((temp->next)->next)->next;
        printf("\nnodes %d and %d removed.\n",r,r+1);
        temp=temp->next;
    }
}

int main()
{
    printf("\ncreate a node first\n");
    int n=create();
    display();
    removeNode(n);
    display();
    return 0;
}