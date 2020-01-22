//Given a sorted linked list, delete all duplicates such that each element appear only once.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* deleteDuplicates(listnode* A) {
    listnode* curr=A;
    while(curr->next!=NULL)
    {
        if(curr&&curr->next)
        {
            if(curr->val==curr->next->val)
            {
                curr->next=curr->next->next;
            }
            else
            {
                curr=curr->next;
            }
            
        }
    }
    return A;
}