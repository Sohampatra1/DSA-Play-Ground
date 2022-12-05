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
    int length{0};
    ListNode* search(ListNode *n, int depth) {
        ++length;
        ListNode *ret;
        if (n->next) ret = search(n->next, depth+1);
        if (length/2+1 == depth) ret = n;
        return ret;
    }
public:
    ListNode* middleNode(ListNode* head) {
        return search(head, 1);
    }
};
