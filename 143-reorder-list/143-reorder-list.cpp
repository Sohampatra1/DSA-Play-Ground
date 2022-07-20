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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* last = NULL;
        while(curr){
            last = curr->next;
            curr->next = prev;
            prev = curr;
            curr = last;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* f1 = head;
        ListNode* f2 = head->next;
        while(f2 && f2->next){
            f1 = f1->next;
            f2 = f2->next->next;
        }
        ListNode* head2 = f1->next;
        f1->next=NULL;
        head2 = reverse(head2);
        f2 = head;
        while(f2 && head2){
            ListNode* last = f2->next;
            ListNode* last2 = head2->next;
            f2->next = head2;
            head2->next = last;
            f2 = last;
            head2 = last2;
        }
    }
};