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
struct node*insert(struct node*head)
{
    int val;
    struct node *newnode,*temp;
    
    printf("Enter value:");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    return head;
}
 int main()
 {
    int ch;
    struct node *head=NULL;
    do
    {
      printf("\n1-Create\n2-Insert at end\n3-Display\n") ;
      printf("Enter choice:");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:head=create(head);
                break;
        case 2:head=insert(head);
                 break;
        case 3:disp(head);
                break;
        default:printf("Invalid choice");
      }
    } while(ch<4);
 }