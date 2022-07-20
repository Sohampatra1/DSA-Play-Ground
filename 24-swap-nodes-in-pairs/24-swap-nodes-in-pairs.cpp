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
	ListNode* swapPairs(ListNode* head) {
		int ct = 0;
		ListNode *curr = head;
		while (curr) {
			curr = curr->next;
			ct++;
		}
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy, *nex = dummy;
		while (ct >= 2) {
			curr = pre->next;
			nex = curr->next;

			curr->next = nex->next;
			nex ->next = pre->next;
			pre->next = nex;
			nex = curr->next;

			ct -= 2;
			pre = curr;
		}
		return dummy->next;
	}
};