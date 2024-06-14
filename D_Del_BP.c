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

NODE *Del(NODE * head)
{
    int pov,i;
    NODE *temp,*p;
    printf("Enter Position to Delete:");
    scanf("%d",&pov);

    if(pov==1)
    {
        p=head;
        head=head->next;
        free(p);
    }
    else
     {
        for(i=1,temp=head;i<pov-1&&temp->next!=NULL;i++,temp=temp->next);
        p=temp->next;
        temp->next=p->next;
        temp->next->prev=temp;
        free(p);
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
    printf("\nLinked list:  ");
    disp(head);
    printf("\n\n   Only Two Chance");
    do
    {
     printf("\n\n  : COMMON DELETION :\n\n");
     head=Del(head);
    printf("After Deletion Linked list:  ");
    disp(head);
    n++; 
    }while(n<2);

}