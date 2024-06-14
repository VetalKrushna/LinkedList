#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next,*prev;
}NODE;

NODE *create(NODE *head)
{
    int i,n;
    NODE *temp,*newnode;
    printf("Enter limit:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->next=NULL;
    printf("Enter Value:");
    scanf("%d",&newnode->data);

    if(head==NULL)
     head=temp=newnode;
    else
     {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
     } 

    }
    return head;
}

NODE *Ins(NODE * head)
{
    int pov,val,i;
    NODE * newnode,*temp;
    printf("Enter Value for newnode :");
    scanf("%d",&val);
    printf("Enter Position to Insert:");
    scanf("%d",&pov);
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=val;

    if(pov==1)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    else
     {
        for(i=1,temp=head;i<pov-1&&temp->next!=NULL;i++,temp=temp->next);
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=newnode;
     }
     return head;
}

void disp(NODE * head)
{
    NODE *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int n=0;
    NODE *head=NULL;
    printf("\n\nCreate linked list:\n\n");
    head=create(head);
    printf("\nLinked list:");
    disp(head);
    do
    {
     printf("\n\n  : COMMON INSERTION :\n\n");
     head=Ins(head);
    printf("\nAfter Insertion Linked list:");
    disp(head);
    n++; 
    }while(n<2);

}