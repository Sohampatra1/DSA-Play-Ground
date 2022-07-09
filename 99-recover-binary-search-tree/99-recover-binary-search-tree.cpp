/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        
        stack<TreeNode *> S;
        
        while(root || !S.empty()) {
            while(root) {
                S.push(root);
                root = root->left;
            }
            
            root = S.top(); S.pop();
            
            if(prev && prev->val > root->val) {
                if(!first) first = prev;
                second = root;
            }
            
            prev = root;
            root = root->right;
        }
        
        swap(first->val , second->val);
    }
};