#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void insertAtBeginning(struct node** h,int d)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=*h;
    *h=n;
}
void insertAtEnd(struct node** h,int d)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(*h==NULL)
    {
        *h=n;
    }
    else
    {
        struct node* curr=*h;
        while(curr->next)
        {
            curr=curr->next;
        }
        curr->next=n;
    }
}
void insertAtPosition(struct node** h,int d,int pos)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    if(pos==1)
    {
        insertAtBeginning(h,d);
    }
    else
    {
        struct node* curr=*h;
        int i=0;
        while(curr&&i<pos-1)
        {
            curr=curr->next;
            i++;
        }
        if(curr==NULL)
        {
            printf("Position doesn't exist");
        }
        else
        {
            n->next=curr->next;
            curr->next=n;
        }
    }
}
void deleteAtBeginning(struct node** h)
{
    struct node* temp=*h;
    *h=(*h)->next;
    free(temp);
    temp=NULL;
}
void deleteAtEnd(struct node** h)
{
    struct node* curr=*h;
    while(curr&&curr->next&&curr->next->next)
    {
        curr=curr->next;
    }
    struct node* temp=curr->next;
    curr->next=NULL;
    free(temp);
    temp=NULL;
}
void deleteAtPosition(struct node** h,int pos)
{
    int i=0;
    if(pos==1)
    {
        deleteAtBeginning(h);
    }
    else
    {
        struct node* curr=*h;
        while(curr&&i<pos-1)
        {
            curr=curr->next;
            i++;
        }
       // if(!curr||!curr->next)
        //{
            struct node* temp=curr->next;
            curr->next=curr->next->next;
            free(temp);
            temp=NULL;
       // }
    }
    
}
void display(struct node** h)
{
    struct node* curr=*h;
    while(curr)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
int main()
{
    struct node* head=NULL;
    insertAtBeginning(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    insertAtPosition(&head,1,3);
    
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head,2);
    display(&head);
}