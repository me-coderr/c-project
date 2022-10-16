/*Write a program to delete the last occurrence of a given character in a single linked list.*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *head=NULL;

void create(int n)
{
    struct node *newnode, *temp;
    char junk;
    for(int i=1;i<=n;i++)
    {
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%c",&junk);
        printf("\nenter the character for node %d:\n",i);
        scanf("%c",&newnode->data);
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
    while(temp!=NULL)
    {
        printf("%c\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse()
{
    struct node *temp=head, *prev=head, *curr=head;
    
    temp=temp->next;
    prev->next=NULL;
    curr=temp;
    while(temp!=NULL)
    {
        temp=temp->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}

void removeChar(char c)
{
    int f=0;
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        if((temp->next)->data==c)
        {
            temp->next=(temp->next)->next;
            printf("\ncharacter found and removed successfully");
            f=1;
            break;
        }
    }
    if(f==0)
    {
        printf("\nelement not present in the list\n");
    }
}

int main()
{
    int n;
    char c, junk;
    printf("\nenter the number of node:\n");
    scanf("%d",&n);
    create(n);
    printf("\nthe list you entered:\n");
    display();
    reverse();
    display();
    scanf("%c",&junk);
    printf("\nenter the character whose last occurance is to be removed:\n");
    scanf("%c",&c);
    removeChar(c);
    printf("\nthe new list :\n");
    reverse();
    display();
    return 0;
}