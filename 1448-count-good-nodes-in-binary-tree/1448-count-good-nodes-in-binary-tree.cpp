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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        helper(root, root->val);
     return ans;
    }
    
    void helper(TreeNode* root, int mx) {
        if(!root) return;
        if(root->val>=mx) ans++, mx = root->val;
        if(root->left) helper(root->left, mx);
        if(root->right) helper(root->right, mx);
     return;
    }
};