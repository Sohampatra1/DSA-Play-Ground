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
#include<vector>
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        vector<int> ans;
        ListNode* temp = head;
        while(temp!=NULL){
            int val = temp -> val;
            ans.push_back(val);
            temp = temp -> next;
        }
        temp = head;
        sort(ans.begin(),ans.end());
        int n= ans.size();
        for(int i =0; i<n ; i++){
            temp -> val = ans[i];
            temp = temp ->next;
        }
        return head;
    }
};