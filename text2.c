/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head; 
    node* cur=head->next;
    node* sorthead=head;
    sorthead->next=NULL;
    while(cur)
    {
        node* next=cur->next;
        //头插
        if(cur->val<=sorthead->val)
        {
           cur->next=sorthead;
           sorthead=cur;
        }
        else
        {
            node* sortprev=sorthead;
            node* sortcur=sorthead->next;
            while(sortcur)
            {
                //中间插
                if(cur->val<=sortcur->val)
                {
                    sortprev->next=cur;
                    cur->next=sortcur;
                    break;
                }
                else
                {
                    sortprev=sortcur;
                    sortcur=sortcur->next;
                }
            }
            //尾插
            if(sortcur==NULL)
            {
                sortprev->next=cur;
                cur->next=NULL;
            }
        }
        cur=next;

    }
    return sorthead;
}