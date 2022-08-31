class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *temp = head;
        if(temp->val == temp->next->val)
        {
            temp = temp->next;
            while(temp && temp->next && temp->next->val == temp->val)
                temp = temp->next;
            
            head = temp;
            return deleteDuplicates(head->next);
        }
        else
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};