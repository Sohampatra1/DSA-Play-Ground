class Solution {
public:
    Node* flatten(Node* head) {
      Node *cur=head,*nxt,*temp;
        while(cur)
        {
            if(cur->child)
            {
                temp=cur->next;
                if(temp)
                temp->prev=NULL;
                cur->next=cur->child;
                cur->next->prev=cur;
                cur->child=NULL;
                
                nxt=cur->next;
                while(nxt->next)
                    nxt=nxt->next;
                nxt->next=temp;
                if(nxt->next)
                    nxt->next->prev=nxt;
            }
            cur=cur->next;
        }
        return head;
    }
};