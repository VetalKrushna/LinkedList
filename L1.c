#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node * create(struct node* head)
{
   int i,n;
   struct node *newnode,* temp;
   printf("Enter limit:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("Enter value:");
     scanf("%d",&newnode->data);
     newnode->next=NULL;

     if(head==NULL)
       head=temp=newnode;
     else 
     {
        temp->next=newnode;
        temp=newnode;
     }    
   } 
    return head;
}

void disp(struct node * head)
{
    struct node * temp;
    printf("\nLinked List:");
    for(temp=head;temp!=NULL;temp=temp->next)
        printf("%d ",temp->data);
}
 int main()
 {
    int ch;
    struct node *head=NULL;
    head=create(head);
    disp(head);    
 }