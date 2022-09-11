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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *curr = head;
        while (curr && curr->next) {
            ListNode *dummy = curr->next;
            ListNode **insert = &head;
            while (*insert != dummy) {
                if (dummy->val < (*insert)->val) break;
                else insert = &(*insert)->next;
            }
            if (*insert == dummy) curr = curr->next;
            else {
                curr->next = dummy->next;
                dummy->next = *insert;
                *insert = dummy;
            }
        }
        return head;
    }
    
   
};