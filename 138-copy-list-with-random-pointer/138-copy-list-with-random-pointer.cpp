/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>  mp;
        Node* copy = NULL;
        Node* temp = NULL;
        Node* node = head;
        while (node) {
            if (copy == NULL) {
                temp = copy = new Node(node->val);
            } else {
                temp->next = new Node(node->val);
                temp = temp->next;
            }
            mp[node] = temp;
            node = node->next;
        }
        node = head;
        temp = copy;
        while (node) {
            temp->random = mp[node->random];
            node = node->next;
            temp = temp->next;
        }
        return copy;
    }
};