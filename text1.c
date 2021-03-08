/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* n1=NULL;
        ListNode* n2=head;
        ListNode* n3=head->next;
        
        while(n3)
        {
            if(n2->val!=n3->val)
            {
                n1=n2;
                n2=n3;
                n3=n3->next;
            }
            else
            {
                while(n3&&n2->val==n3->val)
                {
                     n3=n3->next;
                }
                
                
                if(n1)
                {
                    n1->next=n3;
                }
                else
                {
                    head=n3;
                }
                while(n2!=n3)
                {
                    ListNode* del=n2;
                    n2=n2->next;
                    
                    free(del);
                }
               if(n3)
               {
                   n3=n2->next;
               }
            }
        }
        return head;
        
    }
};