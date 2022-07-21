class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        if(left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* start = NULL;
        int idx = 1;
        while(curr && idx <= right)
        {
            if(idx == left)
            {
                start = prev;
                
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        while(start->next != prev)
        {
            prev->next = start->next;
            ListNode* tmp = start->next->next;
            start->next->next = curr;
            start->next = tmp;
            curr = prev->next;
        }
        return dummy->next;
    }
};