/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
typedef struct Node node;
struct Node* copyRandomList(struct Node* head) {
	if(head==NULL)
        return NULL;
    
    node* cur=head;
   
  
    //1拷贝
    while(cur)
    {
        node* next=cur->next;
        node* copy=(node*)malloc(sizeof(node));
        copy->random=NULL;
        copy->val=cur->val;
        cur->next=copy;
        
        copy->next=next;
        cur=next;
    }
    //找copy的random
    cur=head;
    while(cur)
    {  
        node* copy=cur->next;

        if(cur->random)
            copy->random=cur->random->next;
        else
            copy->random=NULL;
       
        cur=cur->next->next;

    }
    //拆
    cur=head;
    node* copyhead=cur->next;
    while(cur)
    {
        node* next=cur->next->next;
        node* copy=cur->next;
        cur->next=next;
        if(next)
            copy->next=next->next;
        else
            copy->next=NULL;
        cur=next;
    }

    return copyhead;


}