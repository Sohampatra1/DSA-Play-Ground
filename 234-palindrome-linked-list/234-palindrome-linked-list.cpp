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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> x;
        while(temp!=nullptr){
            x.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0; i < (x.size()/2);i++){
            if(x[i] == x[x.size() - 1 - i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};