/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1=new ListNode(),*dummy2=new ListNode();
        ListNode *cur1=dummy1,*ptr=head,*cur2=dummy2;
        while(ptr)
        {
            if((ptr->val)<x)
            {
                cur1->next=ptr;
                cur1=cur1->next;
            }
            else
            {
                cur2->next=ptr;
                cur2=cur2->next;
            }
            ptr=ptr->next;
        }
        cur1->next=dummy2->next;
        cur2->next=NULL;
        return dummy1->next;
        
        
    }
};
