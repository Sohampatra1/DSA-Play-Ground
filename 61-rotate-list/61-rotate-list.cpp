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

private:

int getSize(ListNode* head){
    ListNode * temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
            
public:
	ListNode* rotateRight(ListNode* head, int k) {
    
    ListNode * ans = head;
    
    if(head==NULL || head->next == NULL) return ans;
    
    int size = getSize(head);
    cout<<size;
    int totalRotate = k % size; 
    int i = 0;                 
                                
    while(i<totalRotate){
        
        ListNode * firstNode = head;
        ListNode * prev = head;
        while(prev->next->next != NULL){
            prev = prev->next;
        }
        ListNode * curr = prev ->next;
        ans = curr;       
        curr->next = firstNode;
        prev->next = NULL;
        head = curr;
        
        i++;
        
    }
    return ans;
	}
};