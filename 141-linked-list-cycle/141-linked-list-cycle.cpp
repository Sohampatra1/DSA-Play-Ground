/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int vis = 1e5+1;
public:
    bool hasCycle(ListNode *head) {
          ListNode *cur = head;
            while(cur != nullptr){
            if(cur->val == vis) return 1;
            cur->val = vis;
            cur = cur->next;
        }
          return 0;
    }
};