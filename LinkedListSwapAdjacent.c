//Swap adjacent nodes of a linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void display(struct node** h)
{
    struct node* curr=*h;
    while(curr)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
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
void swapAdjacent(struct node** h)
{
    if(*h==NULL||(*h)->next==NULL)
    {
        return;
    }
    struct node* first=*h;
    struct node* second=(*h)->next;
    *h=second;
    while(first&&second)
    {
        struct node* temp=second->next;
        second->next=first;
        if(temp==NULL||temp->next==NULL)
        {
            first->next=temp;
            break;
        }
        first->next=temp->next;
        first=temp;
        second=first->next;
    }
    //display(h);
    /*if(first==NULL||second==NULL)
    {
        return first;
    }
    else
    {
        second->next=swapAdjacent(second->next);
        first->next=second->next;
        second->next=first;
        return second;
    }*/
}
int main()
{
    struct node* head=NULL;
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    //insertAtEnd(&head,60);
    display(&head);
    swapAdjacent(&head);
    display(&head);
    //display(swapAdjacent(&head));
}