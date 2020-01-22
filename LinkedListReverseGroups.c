//Reverse a linked list in groups of k

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
struct node* reverse(struct node* ptr1,struct node* ptr2)
{
    struct node* prev=ptr2->next;
        struct node* curr=ptr1;
        struct node* nextt=NULL;
        if(curr)
        {
            nextt=curr->next;
        }
        while(curr->next!=ptr2->next)
        {
            curr->next=prev;
            prev=curr;
            curr=nextt;
            if(curr)
            {
                nextt=nextt->next;
            }
        }
        curr->next=prev;
        prev=curr;
        return prev;
}
struct node* reverse_k(struct node* h,int k)
{
    struct node* ptr1=h;
    struct node* ptr2=h;
    int i=1;
    while(ptr2->next&&i<k)
    {
        ptr2=ptr2->next;
        i++;
    }
    if(ptr2->next==NULL)
    {
        return reverse(ptr1,ptr2);
    }
    ptr2->next=reverse_k(ptr2->next,k);
    return reverse(ptr1,ptr2);
}
int main()
{
    struct node* head=NULL;
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    display(&head);
    struct node* x=(reverse_k(head,3));
    display(&x);
    //display(&head);
}